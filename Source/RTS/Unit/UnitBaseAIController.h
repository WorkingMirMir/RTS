// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnitBaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class RTS_API AUnitBaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	AUnitBaseAIController();

	UFUNCTION(BlueprintCallable)
	void UpdateTargetActor(AActor* const NewTargetActor);

	UFUNCTION(BlueprintCallable)
	void UpdateTargetLocation(const FVector NewTargetLocation);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TargetLocationName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TargetActorName;
};