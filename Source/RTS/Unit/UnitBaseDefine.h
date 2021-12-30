// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UnitBaseDefine.generated.h"

UENUM(BlueprintType)
enum class ETribe : uint8
{
	Human,
	Orc
};

UENUM(BlueprintType)
enum class EUintType : uint8
{
	Citizen,
	Infantry,
	Cavalry,
	Magic,
	Special,
};

USTRUCT(Atomic, BlueprintType)
struct FUnitStatus
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ATK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DEF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Sight;
};

UCLASS()
class RTS_API UUnitBaseDefine : public UObject
{
	GENERATED_BODY()
	
};
