// Fill out your copyright notice in the Description page of Project Settings.

#include "VioletRayne.h"
#include "Rayne.h"
#include "PaperSpriteComponent.h"

DEFINE_LOG_CATEGORY(PlayerLog);
// Sets default values
ARayne::ARayne()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("VisibleComponent"));
	ConstructorHelpers::FObjectFinder<UPaperSprite> playerAsset(TEXT("PaperSprite'/Game/Assets/Lucina.Lucina'"));

	RootComponent = playerSprite;
	playerSprite->SetSprite(playerAsset.Object);
	playerSprite->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	playerSprite->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	playerSprite->SetCollisionProfileName(FName("Pawn"));

	RootComponent->SetWorldLocation(FVector::ZeroVector);

}

// Called when the game starts or when spawned
void ARayne::BeginPlay()
{
	Super::BeginPlay();
	switchDirection = FVector(-1.0f, 0.0f, -1.0f);
	moveSpeed = FVector(100.0f, 0.0f, 100.0f);
}

// Called every frame
void ARayne::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector currentLocation = GetActorLocation();
	FVector projectedLocation = GetActorLocation() + moveVelocity * DeltaTime;
	SetActorLocation(projectedLocation, true);

}

// Called to bind functionality to input
void ARayne::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis(FName("MoveLeftRight"), this, &ARayne::MoveLeftRight);
	InputComponent->BindAxis(FName("MoveUpDown"), this, &ARayne::MoveUpDown);
	InputComponent->BindAction(FName("Dash"),EInputEvent::IE_Pressed,this,&ARayne::StartDash);
	InputComponent->BindAction(FName("Dash"), EInputEvent::IE_Released, this, &ARayne::EndDash);

}

void ARayne::MoveLeftRight(float axisValue)
{
	direction.X = FMath::Clamp(axisValue, -1.0f, 1.0f);
	moveVelocity.X = moveSpeed.X * direction.X;
}
void ARayne::MoveUpDown(float axisValue)
{
	direction.Z = FMath::Clamp(axisValue, -1.0f, 1.0f);
	moveVelocity.Z = moveSpeed.Z * direction.Z;
}

void ARayne::StartDash()
{
	isDashing = true;
}

void ARayne::EndDash()
{
	isDashing = false;
}

