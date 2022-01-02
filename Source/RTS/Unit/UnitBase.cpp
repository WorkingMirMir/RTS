// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"
#include "Components/DecalComponent.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetupAttachment(RootComponent);
	DecalComponent->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(-90.0f, 0.0f, 0.0f));
	DecalComponent->SetRelativeScale3D(FVector(0.405f, 0.405f, 0.405f));
	DecalComponent->SetVisibility(false);
}

void AUnitBase::OnSelected()
{
	if (!ensure(DecalComponent != nullptr)) return;
	DecalComponent->SetVisibility(true);
}

void AUnitBase::OnNotSelected()
{
	if (!ensure(DecalComponent != nullptr)) return;
	DecalComponent->SetVisibility(false);
}
/*
// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnitBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
*/