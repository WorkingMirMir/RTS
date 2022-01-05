// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"

#include "Components/DecalComponent.h"
#include "Components/WidgetComponent.h"

#include "UnitBaseAIController.h"

// Sets default values
AUnitBase::AUnitBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetupAttachment(RootComponent);
	DecalComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(-90.0f, 0.0f, 0.0f));
	DecalComponent->SetRelativeScale3D(FVector(0.405f, 0.405f, 0.405f));
	DecalComponent->SetVisibility(false);

	BarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("BarWidget"));
	BarWidget->SetupAttachment(RootComponent);
	BarWidget->SetWidgetSpace(EWidgetSpace::World);

	AIControllerClass = AUnitBaseAIController::StaticClass();
	UE_LOG(LogTemp, Warning, TEXT("AIControllerClass : %s"), *AIControllerClass->GetName());
}

void AUnitBase::OnSelected()
{
	if (!ensure(DecalComponent != nullptr)) return;

	DecalComponent->SetVisibility(true);
}

void AUnitBase::OnNotSelected()
{
	if (!ensure(DecalComponent != nullptr)) return;

	DecalComponent->SetVisibility(false);
}

void AUnitBase::MoveToLocation(const FVector TargetLocation)
{
	if (!ensure(AIController != nullptr)) return;
	if (AIController != nullptr)
	{
		AIController->UpdateTargetLocation(TargetLocation);
	}
}

void AUnitBase::MoveToActor(AActor* const NewTargetActor)
{
	if (!ensure(AIController != nullptr)) return;
	if (AIController != nullptr)
	{
		AIController->UpdateTargetActor(NewTargetActor);
	}
}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();
	BarWidget->SetWidgetSpace(EWidgetSpace::Screen);
}
/*
// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnitBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
*/