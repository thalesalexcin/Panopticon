// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BubblesGenerator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UBubblesGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	uint8 Row = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	uint8 Column = 5;

	// Sets default values for this component's properties
	UBubblesGenerator();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	float _CellWidth;
	float _CellHeigth;
};
