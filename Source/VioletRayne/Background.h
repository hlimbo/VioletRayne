// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Background.generated.h"

UCLASS()
class VIOLETRAYNE_API ABackground : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackground(const FObjectInitializer& OI);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void SetViewDimensions(FVector2D& Dimension);

private:
	class UPaperSpriteComponent* Sprite;
	
	
};
