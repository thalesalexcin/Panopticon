// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "CityMap.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UCityMap : public USceneComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsGrabingRightHand = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsGrabingLeftHand = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsPinchingRightHand = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool IsPinchingLeftHand = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector LeftHandPosition = VectorNull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector RightHandPosition = VectorNull;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SpeedTranslation = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SpeedRotation = 100;

	// Sets default values for this component's properties
	UCityMap();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void UCityMap::Translate(FVector direction);
private:
	FVector VectorNull = FVector(0,0,0);
	FVector LastRightHandPosition = VectorNull;
	FVector LastLeftHandPosition = VectorNull;

	bool DoTrace(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams);
};
