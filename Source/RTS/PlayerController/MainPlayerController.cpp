// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "../Camera/MainCamera.h"
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
	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;
	if (World)
	{
		ClientSetHUD(World->GetAuthGameMode()->HUDClass);
		World->GetGameViewport()->SetMouseLockMode(EMouseLockMode::LockAlways);
	}
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!ensure(InputComponent != nullptr)) return;
	InputComponent->BindAxis("ZoomInOut", this, &AMainPlayerController::ZoomInOut);
	InputComponent->BindAction("StartSelect", IE_Pressed, this, &AMainPlayerController::StartSelect);
	InputComponent->BindAction("StopSelect", IE_Released, this, &AMainPlayerController::StopSelect);
}

void AMainPlayerController::ZoomInOut(const float AxisValue)
{
	AMainCamera* const MainCamera = Cast<AMainCamera>(GetViewTarget());
	if (!ensure(MainCamera != nullptr)) return;
	MainCamera->ZoomInOut(-AxisValue);
}

void AMainPlayerController::StartSelect()
{

}

void AMainPlayerController::StopSelect()
{

}
