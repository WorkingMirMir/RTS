// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDCanvas.h"

#include "../Unit/UnitBase.h"

AHUDCanvas::AHUDCanvas()
	: DrawedRectangleColor(0, 1, 0, 0.15f)
	, StartPosition(0.0f, 0.0f)
	, bIsDrawing(false)
{
}

void AHUDCanvas::DrawHUD()
{
	Super::DrawHUD();

	if (bIsDrawing)
	{
		for (const auto& Unit : FoundUnits)
		{
			Unit->OnNotSelected();
		}

		FoundUnits.Reset();

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			UGameViewportClient* const Viewport = World->GetGameViewport();
			if (!ensure(Viewport != nullptr)) return;

			FVector2D EndPosition;
			Viewport->GetMousePosition(EndPosition);
			DrawRect(DrawedRectangleColor, StartPosition.X, StartPosition.Y, EndPosition.X - StartPosition.X, EndPosition.Y - StartPosition.Y);
			bool bCanGetActors = GetActorsInSelectionRectangle<AUnitBase>(StartPosition, EndPosition, FoundUnits, false, false);

			if (bCanGetActors == false)
			{
				return;
			}
		}

		for (const auto& Unit : FoundUnits)
		{
			Unit->OnSelected();
		}
	}
}

void AHUDCanvas::StartSelect()
{
	UE_LOG(LogTemp, Display, TEXT("StartSelect"));

	UWorld* const World = GetWorld();
	if (!ensure(World != nullptr)) return;

	UGameViewportClient* const Viewport = World->GetGameViewport();
	if (!ensure(Viewport != nullptr)) return;

	Viewport->GetMousePosition(StartPosition);
	bIsDrawing = true;
}

void AHUDCanvas::StopSelect()
{
	UE_LOG(LogTemp, Display, TEXT("StopSelect"));

	bIsDrawing = false;
}