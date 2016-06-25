// Fill out your copyright notice in the Description page of Project Settings.

#include "VioletRayne.h"
#include "VRGameMode.h"
#include "Background.h"
#include "Camera.h"
#include "Rayne.h"
#include "Kismet/GameplayStatics.h"

void AVRGameMode::StartPlay() {
	Super::StartPlay();
	UWorld* const World = GetWorld();
	if (World) {
		ABackground* BG = World->SpawnActor<ABackground>(ABackground::StaticClass());
		ACamera* Camera = World->SpawnActor<ACamera>(ACamera::StaticClass());
		FVector2D Dimensions = Camera->GetViewDimensions();
		BG->SetViewDimensions(Dimensions);
		BG->SetActorLocation(FVector(BG->GetActorLocation().X, -50.0f, BG->GetActorLocation().Z));


		ARayne* player = World->SpawnActor<ARayne>(ARayne::StaticClass());

		//find the camera
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->bAutoManageActiveCameraTarget = false;
		PlayerController->SetViewTarget(Camera);
	}
}




