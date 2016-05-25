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
}


// Called every frame
void UBubblesGenerator::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	// INIT
	if (setCells)
	{
		//GRID
		_CellWidth = boundsMax.X * 2 / Column;
		_CellHeigth = boundsMax.Y * 2 / Row;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("CellWidth: %f CellHeight: %f"), _CellWidth, _CellHeigth));
		cells = new FVector2D*[Column];
		for (int i = 0; i < Column; i++)
		{
			cells[i] = new FVector2D[Row];
		}
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Row; j++)
			{
				cells[i][j] = {(boundsMin.X + _CellWidth / 2 + i * _CellWidth), (boundsMax.Y - _CellHeigth / 2 - j * _CellHeigth)};
			}
		}
		setCells = false;
		//BUBBLE WEIGHTED ARRAY
		int weightsSize = BubbleWeights.Num() - 1;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("weightsSize: %d"), BubbleWeights[0].Weight));

		for (int i = 0; i < weightsSize; i++)
			SumBubbleWeights += BubbleWeights[i].Weight;

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("SumBubbleWeights: %d"), SumBubbleWeights));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("weightsSize: %d"), weightsSize));
		typeWeightedList = new EBubbleType[SumBubbleWeights];
		int index = 0;
		for (int i = 0; i < weightsSize; i++)
		{
			for (int j = 0; j < BubbleWeights[i].Weight; j++)
			{
				typeWeightedList[index] = BubbleWeights[i].BubbleType;
				index++;
			}
		}
	}
	
	// ...
}

FVector UBubblesGenerator::getSpawnPos(int X, int Y)
{
	FVector position;
	position.X = cells[X][Y].X + FMath::FRandRange(-(_CellWidth / (2 * Column) - _BubbleSize), (_CellWidth / (2 * Column) - _BubbleSize));
	position.Y = cells[X][Y].Y + FMath::FRandRange(-(_CellHeigth / (2 * Row) - _BubbleSize), (_CellHeigth / (2 * Row) - _BubbleSize));
	position.Z = 0.0f;

	return position;
}


EBubbleType UBubblesGenerator::getPicto()
{
	//random dans la liste typeWeightedList
	int randomIndex = FMath::RandRange(0, SumBubbleWeights-1);
	EBubbleType randomType = typeWeightedList[randomIndex];
	return randomType;
}
