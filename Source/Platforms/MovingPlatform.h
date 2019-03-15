// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta=(MakeEditWidget=true))
	FVector targetLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:

	FVector globalStartLocation;
	FVector globalTargetLocation;

	UPROPERTY(EditAnywhere)
	int activeTrigger = 1;
};
