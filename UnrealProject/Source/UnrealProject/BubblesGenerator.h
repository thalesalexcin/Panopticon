// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BubblesGenerator.generated.h"

UCLASS()
class UNREALPROJECT_API ABubblesGenerator : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
		uint8 Row = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
		uint8 Column = 5;

	// Sets default values for this actor's properties
	ABubblesGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


private:
	float _CellWidth;
	float _CellHeigth;
};
