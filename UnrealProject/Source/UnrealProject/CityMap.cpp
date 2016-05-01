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
	owner->AddActorLocalOffset(direction);
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
   
	FHitResult HitCall1(ForceInit);
	FCollisionQueryParams ParamsCall1 = FCollisionQueryParams(true);	

	bool traced = DoTrace(&HitCall1, &ParamsCall1);
	{
		if (IsGrabingRightHand && !IsGrabingLeftHand)
		{
			if (LastRightHandPosition == VectorNull)
				LastRightHandPosition = RightHandPosition;
			else
			{	
				FVector diff = RightHandPosition - LastRightHandPosition;
				diff.Z = 0;
				Translate(diff*DeltaTime*SpeedTranslation);
			}
		}

		else if (IsGrabingRightHand && IsGrabingLeftHand) 
		{
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

				FVector scaleVector = FVector(scale, scale, scale) * DeltaTime * ScaleSpeed;


				//pivot
				//if (traced) {
				//	//HitCall1.ImpactPoint
				//	FVector pivot = GetAttachParent()->GetRelativeTransform().TransformPosition(HitCall1.ImpactPoint);
				//	
				//	FVector pivor2 = GetAttachParent()->GetOwner()->GetPivotOffset();
				//	GetAttachParent()->GetOwner()->SetPivotOffset(pivot);

				//	
				//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Pivot: %f, %f, %f"), pivot.X, pivot.Y, pivot.Z));
				//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("pivor2: %f, %f, %f"), pivor2.X, pivor2.Y, pivor2.Z));

				//}

				GetAttachParent()->SetWorldScale3D(GetAttachParent()->RelativeScale3D + scaleVector);

				FVector cross = FVector::CrossProduct(lastVector, currentVector);
				FVector vN = World->GetFirstPlayerController()->PlayerCameraManager->TransformComponent->GetForwardVector();


				if(FVector::DotProduct(vN, cross) > 0)
					angle = -angle;

				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, GetName()); //city actor
				AddLocalRotation(FRotator(0, angle * SpeedRotation * DeltaTime,0));
			}

		
			LastRightHandPosition = RightHandPosition;
			LastLeftHandPosition = LeftHandPosition;
		}
		else 
		{
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

	//Pivot
	{
		FVector localPoint = GetComponentTransform().InverseTransformPosition(HitCall1.ImpactPoint);
		FVector currentChildPosition = -GetRelativeTransform().TransformPosition(FVector::ZeroVector);
		FVector currentParentPosition = GetAttachParent()->GetRelativeTransform().TransformPosition(FVector::ZeroVector);
		FVector newChildPosition = localPoint;

		FVector displacement = newChildPosition - currentChildPosition;
		FVector parentDisplacement = GetAttachParent()->GetRelativeTransform().TransformVector(displacement);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("localPoint: %f, %f, %f"), localPoint.X, localPoint.Y, localPoint.Z));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("currentChildPosition: %f, %f, %f"), currentChildPosition.X, currentChildPosition.Y, currentChildPosition.Z));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("displacement: %f, %f, %f"), -displacement.X, -displacement.Y, -displacement.Z));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("parentDisplacement: %f, %f, %f"), parentDisplacement.X, parentDisplacement.Y, parentDisplacement.Z));

		if (SetPivot && !SetPivotFlag)
		{
			SetPivotFlag = true;
			AddLocalOffset(-displacement);
			GetAttachParent()->AddLocalOffset(parentDisplacement);
		}

		if (!SetPivot && SetPivotFlag)
			SetPivotFlag = false;

		FVector pivotPoint = GetAttachParent()->GetComponentTransform().TransformPosition(FVector::ZeroVector);
		DrawDebugSphere(World, pivotPoint, 10, 10, FColor::Red);
	}

	//Raytrace
	if(traced)
		DrawDebugSphere(World, HitCall1.ImpactPoint, 10, 10, FColor::Emerald);
}

