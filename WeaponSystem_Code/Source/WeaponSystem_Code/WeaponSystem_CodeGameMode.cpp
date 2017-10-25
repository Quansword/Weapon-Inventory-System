// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "WeaponSystem_CodeGameMode.h"
#include "WeaponSystem_CodeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaponSystem_CodeGameMode::AWeaponSystem_CodeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
