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

void UCityMap::Translate(FVector diff, float deltaTime)
{
	diff = GetAttachParent()->GetAttachParent()->GetComponentTransform().InverseTransformVector(diff);
	diff.Z = 0;
	GetAttachParent()->GetAttachParent()->AddLocalOffset(diff * SpeedTranslation * deltaTime);
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

	RV_TraceParams->bTraceComplex = true;
	RV_TraceParams->bTraceAsyncScene = true;
	RV_TraceParams->bReturnPhysicalMaterial = true;

	bool traced = World->LineTraceSingle(*RV_Hit, start, end, ECC_GameTraceChannel1, *RV_TraceParams);
	
	return traced;
}

// Called every frame
void UCityMap::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* owner = GetOwner();
   
	FHitResult HitCall1(ForceInit);
	FCollisionQueryParams ParamsCall1 = FCollisionQueryParams(true);	

	bool traced = DoTrace(&HitCall1, &ParamsCall1);

	{
		if (IsGrabingRightHand && !IsGrabingLeftHand)
		{
			if(LastRightHandPosition != VectorNull)
				Translate(RightHandPosition - LastRightHandPosition, DeltaTime);

			LastRightHandPosition = RightHandPosition;
		}

		else if (!IsGrabingRightHand && IsGrabingLeftHand)
		{
			if (LastLeftHandPosition != VectorNull)
				Translate(LeftHandPosition - LastLeftHandPosition, DeltaTime);

			LastLeftHandPosition = LeftHandPosition;
		}

		else if (IsGrabingRightHand && IsGrabingLeftHand) 
		{
			//Pivot
			if(!SetPivotFlag && traced)
			{
				FVector localPoint = GetComponentTransform().InverseTransformPosition(HitCall1.ImpactPoint);
				FVector parentPoint = GetRelativeTransform().TransformPosition(localPoint);

				FVector parentDisplacement = GetAttachParent()->GetRelativeTransform().TransformPosition(parentPoint);
				FVector displacement = localPoint;

				SetPivotFlag = true;
				SetRelativeLocation(-displacement);
				GetAttachParent()->SetRelativeLocation(parentDisplacement);
			}

			if (LastRightHandPosition != VectorNull && LastLeftHandPosition != VectorNull) 
			{
				FVector lastVector = LastRightHandPosition - LastLeftHandPosition;
				FVector currentVector = RightHandPosition - LeftHandPosition;

				lastVector.Normalize();
				currentVector.Normalize();

				float cos = FVector::DotProduct(lastVector, currentVector);
				float angle = acosf(cos);
			
				
				float oldDist = FVector::Dist(LastRightHandPosition, LastLeftHandPosition);
				float currentDist = FVector::Dist(RightHandPosition, LeftHandPosition);
				float scale = currentDist - oldDist;

				FVector currentScale = GetAttachParent()->RelativeScale3D;
				FVector scaleVector = currentScale + FVector(scale, scale, scale) * DeltaTime * ScaleSpeed;

				if(scaleVector.X > MaxScale)
					scaleVector = FVector(MaxScale, MaxScale, MaxScale);

				if(scaleVector.X < MinScale)
					scaleVector = FVector(MinScale, MinScale, MinScale);

				GetAttachParent()->SetWorldScale3D(scaleVector);

				FVector cross = FVector::CrossProduct(lastVector, currentVector);
				FVector vN = World->GetFirstPlayerController()->PlayerCameraManager->TransformComponent->GetForwardVector();

				if(FVector::DotProduct(vN, cross) > 0)
					angle = -angle;

				FRotator currentRotation = GetAttachParent()->RelativeRotation;
				FRotator rotationOffset = FRotator(0, angle * SpeedRotation * DeltaTime, 0);
				GetAttachParent()->SetRelativeRotation(currentRotation + rotationOffset);
			}
		
			LastRightHandPosition = RightHandPosition;
			LastLeftHandPosition = LeftHandPosition;
		}
		else 
		{
			SetPivotFlag = false;
			LastRightHandPosition = VectorNull;
			LastLeftHandPosition = VectorNull;
		}
	}

	//Rotation
	{
		float angle = 0;
		if (RotateRight)
			angle = 1;
		if (RotateLeft)
			angle = -1;

		FRotator currentRotation = GetAttachParent()->RelativeRotation;
		FRotator rotationOffset = FRotator(0, angle * SpeedRotation * DeltaTime, 0);
		GetAttachParent()->SetRelativeRotation(currentRotation + rotationOffset);
	}

	//Scale
	{
		float scale = 0;
		if (ZoomIn)
			scale = 1;
		if (ZoomOut)
			scale = -1;

		FVector currentScale = GetAttachParent()->RelativeScale3D;
		FVector scaleVector = FVector(scale, scale, scale) * DeltaTime * ScaleSpeed;
		GetAttachParent()->SetWorldScale3D(currentScale + scaleVector);
	}

	//Raytrace
	if(traced)
		DrawDebugSphere(World, HitCall1.ImpactPoint, 10, 10, FColor::Emerald);

	FVector pivotPoint = GetAttachParent()->GetComponentTransform().TransformPosition(FVector::ZeroVector);
	DrawDebugSphere(World, pivotPoint, 10, 10, FColor::Red);
}

