// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::Setup()
{
	AddToViewport();
	bIsFocusable = true;

	FInputModeUIOnly inputModeData;
	inputModeData.SetWidgetToFocus(TakeWidget());
	inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->SetInputMode(inputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{
	RemoveFromViewport();

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
}

void UMenuWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	if (InLevel == nullptr && InWorld == GetWorld())
	{
		Teardown();
	}
}