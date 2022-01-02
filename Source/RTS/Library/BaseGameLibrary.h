// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Widgets/SWidget.h"
#include "Engine/EngineBaseTypes.h"

#include "BaseGameLibrary.generated.h"

UENUM(BlueprintType)
enum class EInputMode : uint8
{
	GameAndUI	UMETA (DisplayName = "Game And UI"),
	UIOnly		UMETA (DisplayName = "UI Only"),
	GameOnly	UMETA (DisplayName = "Game Only"),
	None		UMETA (DisplayName = "None")
};

USTRUCT(Atomic, BlueprintType)
struct FInputModeData
{
	GENERATED_BODY()

	EInputMode InputMode;
	EMouseCaptureMode MouseCaptureMode;

	FInputModeData()
		: InputMode(EInputMode::None)
		, MouseCaptureMode(EMouseCaptureMode::NoCapture)
	{
	}
};

UCLASS()
class RTS_API UBaseGameLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FInputModeData GetCurrentInputMode(const APlayerController* PlayerController);
};