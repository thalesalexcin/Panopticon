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




	/*
	AActor* owner = GetOwner();

	FVector origin;
	FVector boxExtent;
	owner->GetActorBounds(false, origin, boxExtent);
	

	_CellWidth = boxExtent.X * 2 / Column;
	_CellHeigth = boxExtent.Y * 2 / Row;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Origin: %f, %f, %f"), origin.X, origin.Y, origin.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("CellWidth: %f CellHeight: %f"), _CellWidth, _CellHeigth));*/
	
}


// Called every frame
void UBubblesGenerator::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (setCells)
	{
		//FVector boundsMax = Ground->GetLocalBounds;
			//Ground->Bounds;
		
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
				cells[i][j] = {(boundsMin.X + _CellWidth / 2 + i * _CellWidth + FMath::FRandRange(-(_CellWidth / (2 * Column) -_BubbleSize),(_CellWidth / (2 * Column) - _BubbleSize))),
					(boundsMax.Y - _CellHeigth / 2 - j * _CellHeigth + FMath::FRandRange(-(_CellHeigth / (2 * Row) - _BubbleSize), (_CellHeigth / (2 * Row) - _BubbleSize)))};
				FVector position;
				position.X = cells[i][j].X;
				position.Y = cells[i][j].Y;
				position.Z = 100.0f;

				FVector worldPos = Ground->GetComponentTransform().TransformPosition(position);


				//DrawDebugSphere(World, worldPos, 100, 10, FColor::Green, true);

				//GetWorld()->SpawnActor<Bubble>
				/*if (bubble != NULL)
				{

				}*/
				
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Cell[%d].X: %f Cell[%d].Y: %f"), i, cells[i][j].X, j, cells[i][j].Y));
			}
		}
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("CellSize.X: %f CellSize.Y: %f"), _CellWidth, _CellHeigth));
		//_BubbleSize
		//->getobj
		//World->SpawnActor<UObject>(Bubble, FVector(0.f, 0.f, 300.f), FRotator::ZeroRotator);
		//FVector2D* spawn = new FVector2D(FMath::RandRange(-Column, Column), FMath::RandRange(-Row, Row));
		//cells[spawn.X][spawn.Y];



		setCells = false;
	}
	
	// ...
}

FVector UBubblesGenerator::getSpawnPos(int X, int Y)
{
	FVector position;
	position.X = cells[X][Y].X;
	position.Y = cells[X][Y].Y;
	position.Z = 0.0f;

	return position;
}

