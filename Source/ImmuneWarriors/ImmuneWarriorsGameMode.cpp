// Copyright Epic Games, Inc. All Rights Reserved.

#include "ImmuneWarriorsGameMode.h"
#include "ImmuneWarriorsPlayerController.h"
#include "ImmuneWarriorsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AImmuneWarriorsGameMode::AImmuneWarriorsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AImmuneWarriorsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}