// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCamera.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMainCamera::AMainCamera()
	: MaxSpringArmLength(5000.0f)
	, MinSpringArmLength(1000.0f)
	, MaxZoomVector(20.0f)
	, ZoomVector(MaxZoomVector / 2)
	, MaxCameraMovingSpeed(100.0f)
	, MinCameraMovingSpeed(40.0f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	if (!ensure(SpringArmComponent != nullptr)) return;
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 90.0f, 0.0f));
	SpringArmComponent->TargetArmLength = (MaxSpringArmLength + MinSpringArmLength) / 2.0f;
	SpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	if (!ensure(CameraComponent != nullptr)) return;
	CameraComponent->AttachToComponent(SpringArmComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMainCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* const PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->SetViewTarget(this);
}

// Called every frame
void AMainCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	UGameViewportClient* const Viewport = World->GetGameViewport();
	if (!ensure(Viewport != nullptr)) return;

	FVector2D MousePosition;
	if (!Viewport->GetMousePosition(MousePosition))
	{
		return;
	}

	FVector2D ViewportSize;
	Viewport->GetViewportSize(ViewportSize);

	MoveForward(ViewportSize, MousePosition);
	MoveBackward(ViewportSize, MousePosition);
	MoveRight(ViewportSize, MousePosition);
	MoveLeft(ViewportSize, MousePosition);
}

void AMainCamera::ZoomInOut(const float AxisValue)
{
	checkf(MaxCameraMovingSpeed > MinCameraMovingSpeed && MaxSpringArmLength > MinSpringArmLength
		, TEXT("MainCamera is field Value Error"));

	if (SpringArmComponent != nullptr)
	{
		ZoomVector = FMath::Clamp(AxisValue + ZoomVector, 0.0f, MaxZoomVector);
		const float Distance = (MaxSpringArmLength - MinSpringArmLength) / MaxZoomVector;
		const float Length = (ZoomVector * Distance) + MinSpringArmLength;
		SpringArmComponent->TargetArmLength = Length;
	}
}

float AMainCamera::GetCameraMovingSpeed() const
{
	checkf(MaxCameraMovingSpeed > MinCameraMovingSpeed && MaxSpringArmLength > MinSpringArmLength
		, TEXT("MainCamera is field Value Error"));

	const float Speed = (MaxCameraMovingSpeed - MinCameraMovingSpeed) * UKismetMathLibrary::NormalizeToRange(SpringArmComponent->TargetArmLength,
		MinSpringArmLength, MaxSpringArmLength) + MinCameraMovingSpeed;

	return Speed;
}

void AMainCamera::MoveForward(const FVector2D ViewportSize, const FVector2D MousePosition)
{
	FVector DeltaVector = FVector(0.0f, GetCameraMovingSpeed(), 0.0f);
	const float ClampedFloat = FMath::Clamp(UKismetMathLibrary::NormalizeToRange(MousePosition.Y, 0, ViewportSize.Y * 0.05f), 0.0f, 1.0f);

	DeltaVector *= (1.0f - ClampedFloat);
	RootComponent->AddRelativeLocation(DeltaVector);
}

void AMainCamera::MoveBackward(const FVector2D ViewportSize, const FVector2D MousePosition)
{
	FVector DeltaVector = FVector(0.0f, -GetCameraMovingSpeed(), 0.0f);
	const float ClampedFloat = FMath::Clamp(UKismetMathLibrary::NormalizeToRange(MousePosition.Y, ViewportSize.Y * 0.95f, ViewportSize.Y), 0.0f, 1.0f);

	DeltaVector *= ClampedFloat;
	RootComponent->AddRelativeLocation(DeltaVector);
}

void AMainCamera::MoveLeft(const FVector2D ViewportSize, const FVector2D MousePosition)
{
	FVector DeltaVector = FVector(GetCameraMovingSpeed(), 0.0f, 0.0f);
	const float ClampedFloat = FMath::Clamp(UKismetMathLibrary::NormalizeToRange(MousePosition.X, 0.0f, ViewportSize.X * 0.05f), 0.0f, 1.0f);

	DeltaVector *= (1.0f - ClampedFloat);
	RootComponent->AddRelativeLocation(DeltaVector);
}

void AMainCamera::MoveRight(const FVector2D ViewportSize, const FVector2D MousePosition)
{
	FVector DeltaVector = FVector(-GetCameraMovingSpeed(), 0.0f, 0.0f);
	const float ClampedFloat = FMath::Clamp(UKismetMathLibrary::NormalizeToRange(MousePosition.X, ViewportSize.X * 0.95f, ViewportSize.X), 0.0f, 1.0f);

	DeltaVector *= ClampedFloat;
	RootComponent->AddRelativeLocation(DeltaVector);
}
