// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Rayne.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(PlayerLog, Log, All);
UCLASS()
class VIOLETRAYNE_API ARayne : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARayne();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Control functions
	void MoveLeftRight(float axisValue);
	void MoveUpDown(float axisValue);
	void StartDash();
	void EndDash();


	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* playerSprite;

	UPROPERTY(EditAnywhere)
		FVector moveSpeed;

	FVector direction;
	FVector switchDirection;
	FVector moveVelocity;
	bool isDashing;
	
};
