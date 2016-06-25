// Fill out your copyright notice in the Description page of Project Settings.

#include "VioletRayne.h"
#include "Camera.h"


ACamera::ACamera() {
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CustomCamera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->SetWorldRotation(FRotator(0.0f, -90.0f,0.0f));
	Camera->SetWorldLocation(FVector(0.0f, 50.0f, 0.0f));
	Camera->AttachTo(RootComponent);

}

FVector2D ACamera::GetViewDimensions() {
	FVector2D Dimensions;
	Dimensions.X = Camera->OrthoWidth;
	Dimensions.Y = 1 / (Camera->AspectRatio / Camera->OrthoWidth);
	return Dimensions;
}



