// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "BubblesGenerator.h"


// Sets default values
ABubblesGenerator::ABubblesGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABubblesGenerator::BeginPlay()
{
	Super::BeginPlay();

	FVector origin;
	FVector boxExtent;
	GetActorBounds(false, origin, boxExtent);

	_CellWidth = boxExtent.X * 2 / Column;
	_CellHeigth = boxExtent.Y * 2 / Row;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Origin: %f, %f, %f"), origin.X, origin.Y, origin.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("CellWidth: %f CellHeight: %f"), _CellWidth, _CellHeigth));
}

// Called every frame
void ABubblesGenerator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

