// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "CityMap.h"


// Sets default values for this component's properties
UCityMap::UCityMap()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCityMap::Translate(FVector direction)
{
	AActor* owner = GetOwner();

	owner->FindComponentByClass<USceneComponent>()->AddLocalOffset(direction);
	
}

// Called when the game starts
void UCityMap::BeginPlay()
{
	Super::BeginPlay();
	
	
	// get hands position
	// vector from current hands position and last hands position


	// ...
	
}


// Called every frame
void UCityMap::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector move(0,0,0);
	if (Up)
		move.X += Speed * DeltaTime;

	if (Down)
		move.X -= Speed * DeltaTime;

	if (Left)
		move.Y -= Speed * DeltaTime;

	if (Right)
		move.Y += Speed * DeltaTime;

	if (ZoomIn)
		move.Z += Speed * DeltaTime;

	if (ZoomOut)
		move.Z -= Speed * DeltaTime;

	Translate(move);
	// ...
}

