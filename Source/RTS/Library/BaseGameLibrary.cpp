// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameLibrary.h"

FInputModeData UBaseGameLibrary::GetCurrentInputMode(const APlayerController* const PlayerController)
{
    FInputModeData InputModeData;
    InputModeData.InputMode = EInputMode::None;
    InputModeData.MouseCaptureMode = EMouseCaptureMode::NoCapture;

    if (IsValid(PlayerController))
    {
        UGameViewportClient* GameViewportClient = PlayerController->GetWorld()->GetGameViewport();
        ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

        bool Ignore = GameViewportClient->IgnoreInput();
        EMouseCaptureMode MouseCaptureMode = GameViewportClient->GetMouseCaptureMode();
        InputModeData.MouseCaptureMode = MouseCaptureMode;

        if (Ignore == false && MouseCaptureMode == EMouseCaptureMode::CaptureDuringMouseDown)
        {
            InputModeData.InputMode = EInputMode::GameAndUI;
        }
        else if (Ignore == true && MouseCaptureMode == EMouseCaptureMode::NoCapture)
        {
            InputModeData.InputMode = EInputMode::UIOnly;
        }
        else
        {
            InputModeData.InputMode = EInputMode::GameOnly;
        }
    }

    return InputModeData;
}