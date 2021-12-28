// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCamera.generated.h"

UCLASS()
class RTS_API AMainCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMainCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ZoomInOut(const float AxisValue);

private:
	float GetCameraMovingSpeed() const;
	void MoveForward(const FVector2D ViewportSize, const FVector2D MousePosition);
	void MoveBackward(const FVector2D ViewportSize, const FVector2D MousePosition);
	void MoveLeft(const FVector2D ViewportSize, const FVector2D MousePosition);
	void MoveRight(const FVector2D ViewportSize, const FVector2D MousePosition);

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere)
	float MaxSpringArmLength;

	UPROPERTY(EditAnywhere)
	float MinSpringArmLength;

	UPROPERTY(EditAnywhere)
	float MaxZoomVector;

	UPROPERTY(VisibleAnywhere)
	float ZoomVector;

	UPROPERTY(EditAnywhere)
	float MaxCameraMovingSpeed;

	UPROPERTY(EditAnywhere)
	float MinCameraMovingSpeed;
};