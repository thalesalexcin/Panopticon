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
    AddLocalOffset(direction);
    //AActor* owner = GetOwner();

    //owner->FindComponentByClass<UCityMap>()->AddLocalOffset(direction);

	
}

// Called when the game starts
void UCityMap::BeginPlay()
{
	Super::BeginPlay();
	
	
	// get hands position
	// vector from current hands position and last hands position


	// ...
	
}

bool UCityMap::DoTrace(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams) 
{
	FVector camLoc = World->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
	FRotator rot = World->GetFirstPlayerController()->PlayerCameraManager->GetCameraRotation();

	FVector start = camLoc;
	FVector end = camLoc + (rot.Vector() * 100000);

	//AActor* cam = (AActor*) World->GetFirstPlayerController()->PlayerCameraManager->GetActorClass();

	//RV_TraceParams->AddIgnoredActor(cam);
	RV_TraceParams->bTraceComplex = true;
	RV_TraceParams->bTraceAsyncScene = true;
	RV_TraceParams->bReturnPhysicalMaterial = true;

	bool traced = World->LineTraceSingle(*RV_Hit, start, end, ECC_PhysicsBody, *RV_TraceParams);
	
	return traced;
}

// Called every frame
void UCityMap::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* owner = GetOwner();
    //owner->FindComponentByClass<USceneComponent>();
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, owner->FindComponentByClass<USceneComponent>()->GetName());
	 
	
	
	FHitResult HitCall1(ForceInit);
	FCollisionQueryParams ParamsCall1 = FCollisionQueryParams(true);

	

	if (DoTrace(&HitCall1, &ParamsCall1))
	{
		if (CurrentGrabPosition != VectorNull)
		{
			if (LastGrabPosition == VectorNull)
				LastGrabPosition = CurrentGrabPosition;
			else
			{
				//FVector diffCamera = HitCall1.ImpactPoint - HitCall1.TraceStart;

				//HitCall1.ImpactPoint.
				
				//FVector::VectorPlaneProject(diffCamera,  )
				
				FVector diff = CurrentGrabPosition - LastGrabPosition;
			
				diff *= Speed;

				diff = GetRelativeTransform().TransformVector(diff);

				diff.Z = 0;
				Translate(diff*DeltaTime);
			}
		}
		else
		{
			LastGrabPosition = VectorNull;
		}
	}

	FHitResult HitCall(ForceInit);
	FCollisionQueryParams ParamsCall = FCollisionQueryParams(true);
	

	if (DoTrace(&HitCall, &ParamsCall)) 
	{
		DrawDebugSphere(World, HitCall.ImpactPoint, 10, 10, FColor::Emerald );
		

		FVector diff = HitCall.ImpactPoint - HitCall.TraceStart;
		diff.Normalize();

		diff *= 10;

		if (ZoomIn)
			Translate(-diff);

		if (ZoomOut)
			Translate(diff);
	}

	// ...
}

