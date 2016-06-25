// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Camera.generated.h"

/**
 * 
 */
UCLASS()
class VIOLETRAYNE_API ACamera : public AActor
{
	GENERATED_BODY()
	
public:
	UCameraComponent* Camera;
	ACamera();
	FVector2D GetViewDimensions();
	
	
};
