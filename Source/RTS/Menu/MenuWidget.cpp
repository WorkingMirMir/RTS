// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::Setup()
{
	AddToViewport();
	bIsFocusable = true;

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	OldInputModeData = UBaseGameLibrary::GetCurrentInputMode(PlayerController);

	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{
	RemoveFromViewport();

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->bShowMouseCursor = false;

	switch (OldInputModeData.InputMode)
	{
	case EInputMode::GameAndUI:
		PlayerController->SetInputMode(FInputModeGameAndUI());
		break;
	case EInputMode::UIOnly:
		PlayerController->SetInputMode(FInputModeUIOnly());
		break;
	case EInputMode::GameOnly:
		PlayerController->SetInputMode(FInputModeGameOnly());
		break;
	default:
		check(false);
		break;
	}
	
	UGameViewportClient* const Viewport = World->GetGameViewport();
	if (!ensure(Viewport != nullptr)) return;
	Viewport->SetMouseCaptureMode(OldInputModeData.MouseCaptureMode);
	
	OldInputModeData = FInputModeData();
}

void UMenuWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	if (InLevel == nullptr && InWorld == GetWorld())
	{
		Teardown();
	}
}