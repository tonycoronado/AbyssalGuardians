// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbyssalGuardiansGameMode.h"
#include "AbyssalGuardiansCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAbyssalGuardiansGameMode::AAbyssalGuardiansGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
