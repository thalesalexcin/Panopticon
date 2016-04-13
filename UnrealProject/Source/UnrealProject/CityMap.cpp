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
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if(CurrentGrabPosition != VectorNull)
	{
		if (LastGrabPosition == VectorNull)
			LastGrabPosition = CurrentGrabPosition;
		else
		{
			FVector diff = CurrentGrabPosition - LastGrabPosition;
			diff.Z = 0;
			Translate(diff);
		}
	}
	else 
		LastGrabPosition = VectorNull;
	// ...
}

