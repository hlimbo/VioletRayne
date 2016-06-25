// Fill out your copyright notice in the Description page of Project Settings.

#include "VioletRayne.h"
#include "Background.h"
#include "PaperSpriteComponent.h"

// Sets default values
ABackground::ABackground(const FObjectInitializer& OI):Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UPaperSprite> BackgroundSpriteRef(TEXT("PaperSprite'/Game/Assets/Background.Background'"));
	Sprite = OI.CreateDefaultSubobject<UPaperSpriteComponent>(this, TEXT("SpriteComponent"));
	Sprite->SetSprite(BackgroundSpriteRef.Object);

}

// Called when the game starts or when spawned
void ABackground::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABackground::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABackground::SetViewDimensions(FVector2D& Dimension) {
	FVector scale = Sprite->RelativeScale3D;
	float scaleX, scaleY; 
	scaleX = Dimension.X / Sprite->GetSprite()->GetSourceSize().X;
	scaleY = Dimension.Y / Sprite->GetSprite()->GetSourceSize().Y;
	scale.X = scaleX;
	scale.Z = scaleY;
	Sprite->SetRelativeScale3D(scale);
}

