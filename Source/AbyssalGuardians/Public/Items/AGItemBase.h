// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemDataStructs.h"
#include "AGItemBase.generated.h"

/**
 * 
 */
UCLASS()
class ABYSSALGUARDIANS_API UAGItemBase : public UObject
{
	GENERATED_BODY()

public:
	//==========================================================================
	// PROPERTIES AND VARIABLES
	//==========================================================================

	/*UPROPERTY()
	UInventoryComponent* OwningInventory;*/
	
	UPROPERTY(VisibleAnywhere, Category = "Item Data", meta = (UIMin = 1, UIMax = 99))
	int32 ItemQuantity;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ID;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemStatistics ItemStatistics;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemTextData ItemTextData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemNumericData ItemNumericData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemAssetData ItemAssetData;

	//==========================================================================
	// FUNCTIONS
	//==========================================================================
	UAGItemBase();

	UFUNCTION(Category = "Item")
	UAGItemBase* CreateItemCopy() const;

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const { return ItemQuantity * ItemNumericData.Weight; };
	
	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const { return ItemNumericData.Weight; };
	
	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const { return ItemQuantity == ItemNumericData.MaxStackSize; };

	UFUNCTION(Category = "Item")
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(AAbyssalGuardiansCharacter* Character);
	
protected:

	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;
	}
};
