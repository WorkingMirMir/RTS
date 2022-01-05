// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBaseAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

AUnitBaseAIController::AUnitBaseAIController()
	: TargetLocationName("TargetLocation")
	, TargetActorName("TargetActor")
{
}

void AUnitBaseAIController::UpdateTargetActor(AActor* const NewTargetActor)
{
	UE_LOG(LogTemp, Warning, TEXT("TargetActor"));
	if (Blackboard != nullptr)
	{
		Blackboard->SetValueAsObject(TargetActorName, NewTargetActor);
	}
}

void AUnitBaseAIController::UpdateTargetLocation(const FVector NewTargetLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("TargetLocation"));
	if (Blackboard != nullptr)
	{
		Blackboard->SetValueAsVector(TargetLocationName, NewTargetLocation);
	}
}
