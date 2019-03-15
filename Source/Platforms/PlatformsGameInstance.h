// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMS_API UPlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPlatformsGameInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& address);
};
