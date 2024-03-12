// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AGInteractionInterface.generated.h"

// This defines all the types of things that player can interact with
UENUM()
enum class EInteractableType : uint8
{
	Pickups UMETA(DisplayName = "Pickup"),
	NonPlayerCharacter UMETA(DisplayName = "NonPlayerCharacter"),
	Device UMETA(DisplayName = "Device"),
	Toggle UMETA(DisplayName = "Toggle"),
	Container UMETA(DisplayName = "Container")
};

USTRUCT()
struct FInteractableData
{
	GENERATED_USTRUCT_BODY()

	FInteractableData();

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteractableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;

	UPROPERTY(EditInstanceOnly)
	FText Action;

	// used for pickups
	UPROPERTY(EditInstanceOnly)
	int8 Quantity;

	// used for doors, buttons, valves that required a timer for duration
	UPROPERTY(EditInstanceOnly)
	float InteractionDuration; 
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAGInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ABYSSALGUARDIANS_API IAGInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void BeginFocus();
	virtual void EndFocus();
	virtual void BeginInteract();
	virtual void EndInteract();
	virtual void Interact();

	FInteractableData InteractableData;
};
