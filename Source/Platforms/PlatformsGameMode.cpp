// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlatformsGameMode.h"
#include "PlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlatformsGameMode::APlatformsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
