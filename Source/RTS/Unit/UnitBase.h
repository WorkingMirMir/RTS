// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../Interface/Selectedable.h"
#include "UnitBaseDefine.h"

#include "UnitBase.generated.h"

UCLASS()
class RTS_API AUnitBase : public ACharacter, public ISelectedable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUnitBase();

	UFUNCTION(BlueprintCallable)
	virtual void OnSelected();

	UFUNCTION(BlueprintCallable)
	virtual void OnNotSelected();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FName GetName() const { return Name; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE ETribe GetTribe() const { return Tribe; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EUintType GetType() const { return Type; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetMaxHP() const { return Status.MaxHP; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetHP() const { return Status.HP; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetMaxMP() const { return Status.MaxMP; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetMP() const { return Status.MP; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetATK() const { return Status.ATK; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetDEF() const { return Status.DEF; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetSight() const { return Status.Sight; }

/*
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
*/
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
