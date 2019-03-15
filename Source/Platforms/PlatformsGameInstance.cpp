// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformsGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UPlatformsGameInstance::UPlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{

}

void UPlatformsGameInstance::Init()
{

}

void UPlatformsGameInstance::Host()
{
	UEngine* engine = GetEngine();
	if (!ensure(engine != nullptr)) return;

	engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	UWorld* world = GetWorld();
	if (!ensure(world != nullptr)) return;

	world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");


}

void UPlatformsGameInstance::Join(const FString& address)
{
	UEngine* engine = GetEngine();
	if (!ensure(engine != nullptr)) return;

	engine->AddOnScreenDebugMessage(0, 7, FColor::Yellow, FString::Printf(TEXT("Joining on server: %s"), *address));
	APlayerController* playerController = GetFirstLocalPlayerController();
	playerController->ClientTravel(*address, ETravelType::TRAVEL_Absolute);
}