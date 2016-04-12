// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "BubblesGenerator.h"


// Sets default values for this component's properties
UBubblesGenerator::UBubblesGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBubblesGenerator::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();

	FVector origin;
	FVector boxExtent;
	owner->GetActorBounds(false, origin, boxExtent);

	_CellWidth = boxExtent.X * 2 / Column;
	_CellHeigth = boxExtent.Y * 2 / Row;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Origin: %f, %f, %f"), origin.X, origin.Y, origin.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("CellWidth: %f CellHeight: %f"), _CellWidth, _CellHeigth));
	
}


// Called every frame
void UBubblesGenerator::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

