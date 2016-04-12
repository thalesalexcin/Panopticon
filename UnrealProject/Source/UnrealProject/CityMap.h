// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "CityMap.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UCityMap : public USceneComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool Up = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool Down = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool Right = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool Left = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 100;

	// Sets default values for this component's properties
	UCityMap();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void UCityMap::Translate(FVector direction);
	
};
