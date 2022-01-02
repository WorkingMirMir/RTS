// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "GameFramework/HUD.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "../Camera/MainCamera.h"
#include "../HUD/HUDCanvas.h"
#include "../Unit/UnitBase.h"
#include "../RTSGameModeBase.h"


AMainPlayerController::AMainPlayerController()
{
	DefaultClickTraceChannel = ECollisionChannel::ECC_Camera;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!ensure(InputComponent != nullptr)) return;
	InputComponent->BindAxis("ZoomInOut", this, &AMainPlayerController::ZoomInOut);
	InputComponent->BindAction("Select", IE_Pressed, this, &AMainPlayerController::StartSelect);
	InputComponent->BindAction("Select", IE_Released, this, &AMainPlayerController::StopSelect);
	InputComponent->BindAction("MoveUnit", IE_Released, this, &AMainPlayerController::MoveUnit);
}

void AMainPlayerController::ZoomInOut(const float AxisValue)
{
	AMainCamera* const MainCamera = Cast<AMainCamera>(GetViewTarget());
	if (MainCamera)
	{
		MainCamera->ZoomInOut(-AxisValue);
	}
}

void AMainPlayerController::StartSelect()
{
	AHUDCanvas* const HUD = Cast<AHUDCanvas>(GetHUD());
	if (HUD)
	{
		HUD->StartSelect();
	}
}

void AMainPlayerController::StopSelect()
{
	AHUDCanvas* const HUD = Cast<AHUDCanvas>(GetHUD());
	if (HUD)
	{
		HUD->StopSelect();
		SelectedUnits = HUD->GetFoundUnits();
	}
}

void AMainPlayerController::MoveUnit()
{
	UE_LOG(LogTemp, Warning, TEXT("MoveUnit"));
	for (const auto& Unit : SelectedUnits)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
		const FVector MoveLocation = Hit.Location;
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(Unit->GetController(), MoveLocation);
	}
}
