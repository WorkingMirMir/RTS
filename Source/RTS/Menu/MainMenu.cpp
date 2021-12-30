// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/Image.h"
#include "Components/WidgetSwitcher.h"
#include "UObject/ConstructorHelpers.h"

bool UMainMenu::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess)
	{
		return false;
	}

	if (!ensure(StartGameButton != nullptr)) return false;
	StartGameButton->OnClicked.AddDynamic(this, &UMainMenu::OnStartGameButtonClick);

	if (!ensure(OptionButton != nullptr)) return false;
	OptionButton->OnClicked.AddDynamic(this, &UMainMenu::OnOptionButtonClick);

	if (!ensure(QuitGameButton != nullptr)) return false;
	QuitGameButton->OnClicked.AddDynamic(this, &UMainMenu::OnQuitGameButtonClick);

	if (!ensure(OkButton != nullptr)) return false;
	OkButton->OnClicked.AddDynamic(this, &UMainMenu::OnOkButtonClick);

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::OnCancelButtonClick);

	return true;
}

void UMainMenu::OnStartGameButtonClick()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(LoginMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(LoginMenu);
	UE_LOG(LogTemp, Display, TEXT("OnStartGameButtonClick : %d"), MenuSwitcher->GetActiveWidgetIndex());
}

void UMainMenu::OnOptionButtonClick()
{
	//Visibility = ESlateVisibility::Hidden;
}

void UMainMenu::OnQuitGameButtonClick()
{
	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ConsoleCommand("quit");
}

void UMainMenu::OnOkButtonClick()
{
	//TODO : Send Packet
}

void UMainMenu::OnCancelButtonClick()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(MainMenu);
	UE_LOG(LogTemp, Display, TEXT("OnCancelButtonClick : %d"), MenuSwitcher->GetActiveWidgetIndex());
}