// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "MenuWidget.h"

#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class RTS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void OnStartGameButtonClick();

	UFUNCTION()
	void OnOptionButtonClick();

	UFUNCTION()
	void OnQuitGameButtonClick();
	
	UFUNCTION()
	void OnOkButtonClick();

	UFUNCTION()
	void OnCancelButtonClick();

protected:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UButton* StartGameButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* OptionButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitGameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* OkButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* LoginMenu;
};