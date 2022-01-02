// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RTS_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainPlayerController();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
	void ZoomInOut(const float AxisValue);

	UFUNCTION(BlueprintCallable)
	void StartSelect();

	UFUNCTION(BlueprintCallable)
	void StopSelect();

	UFUNCTION(BlueprintCallable)
	void MoveUnit();

private:
	TArray<class AUnitBase*> SelectedUnits;
};