// Fill out your copyright notice in the Description page of Project Settings.


#include "ImmuneWarriorsLevelGameModeBase.h"


#include "Warriors/WarriorBase.h"
#include "WarriorPlayerControllerBase.h"
#include "UObject/ConstructorHelpers.h"
AImmuneWarriorsLevelGameModeBase::AImmuneWarriorsLevelGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWarriorPlayerControllerBase::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Warriors/WarriorBase"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


}