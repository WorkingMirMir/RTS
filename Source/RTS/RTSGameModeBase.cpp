// Copyright Epic Games, Inc. All Rights Reserved.


#include "RTSGameModeBase.h"

#include "HUD/HUDCanvas.h"
#include "PlayerController/MainPlayerController.h"
//#include "PlayerState/MainPlayerState.h"


ARTSGameModeBase::ARTSGameModeBase()
{
	DefaultPawnClass = nullptr;
	HUDClass = AHUDCanvas::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	//PlayerStateClass = AMainPlayerState::StaticClass();
	SpectatorClass = nullptr;
}