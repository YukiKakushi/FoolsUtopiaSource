// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pixel3dGameGameMode.h"
#include "Pixel3dGamePlayerController.h"
#include "Pixel3dGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APixel3dGameGameMode::APixel3dGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APixel3dGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}