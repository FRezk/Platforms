// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	globalStartLocation = GetActorLocation();
	globalTargetLocation = GetTransform().TransformPosition(targetLocation);


}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (activeTrigger > 0)
	{
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			float JourneyLength = (globalTargetLocation - globalStartLocation).Size();
			float JourneyTravelled = (Location - globalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector swap = globalStartLocation;
				globalStartLocation = globalTargetLocation;
				globalTargetLocation = swap;
			}

			FVector Direction = (globalTargetLocation - globalStartLocation).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	activeTrigger++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (activeTrigger > 0)
	{
		activeTrigger--;
	}
}