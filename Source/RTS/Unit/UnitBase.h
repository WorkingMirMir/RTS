// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../Interface/Selectable.h"
#include "UnitBaseDefine.h"

#include "UnitBase.generated.h"

UCLASS()
class RTS_API AUnitBase : public ACharacter, public ISelectable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUnitBase();

	virtual void OnSelected();

	virtual void OnNotSelected();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETribe Tribe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUintType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FUnitStatus Status;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UDecalComponent* DecalComponent;
};
