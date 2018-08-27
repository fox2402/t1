// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "t1GameMode.h"
#include "t1HUD.h"
#include "t1Character.h"
#include "UObject/ConstructorHelpers.h"

At1GameMode::At1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = At1HUD::StaticClass();
}
