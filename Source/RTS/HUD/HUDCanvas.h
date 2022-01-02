// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "../Interface/Selectable.h"

#include "HUDCanvas.generated.h"

/**
 * 
 */
UCLASS()
class RTS_API AHUDCanvas : public AHUD, public ISelectable
{
	GENERATED_BODY()
	
public:
	AHUDCanvas();

	virtual void DrawHUD() override;

	virtual void StartSelect();

	virtual void StopSelect();

	TArray<class AUnitBase*> GetFoundUnits() const { return FoundUnits; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor DrawedRectangleColor;

private:
	UPROPERTY(VisibleAnywhere)
	FVector2D StartPosition;

	UPROPERTY(VisibleAnywhere)
	bool bIsDrawing;

	TArray<class AUnitBase*> FoundUnits;
};