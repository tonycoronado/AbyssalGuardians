// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/AGItemBase.h"

UAGItemBase::UAGItemBase()
{
}

UAGItemBase* UAGItemBase::CreateItemCopy() const
{
	UAGItemBase* ItemCopy = NewObject<UAGItemBase>(StaticClass());
	ItemCopy->ID = this->ID;
	ItemCopy->ItemQuantity = this->ItemQuantity;
	ItemCopy->ItemQuality = this->ItemQuality;
	ItemCopy->ItemType = this->ItemType;
	ItemCopy->ItemTextData = this->ItemTextData;
	ItemCopy->ItemNumericData = this->ItemNumericData;
	ItemCopy->ItemStatistics = this->ItemStatistics;
	ItemCopy->ItemAssetData = this->ItemAssetData;

	return ItemCopy;
}

void UAGItemBase::SetQuantity(const int32 NewQuantity)
{
	if (NewQuantity != ItemQuantity)
	{
		ItemQuantity = FMath().Clamp(NewQuantity, 0, ItemNumericData.bIsStackable ? ItemNumericData.MaxStackSize : 1);

		/*if (OwningInventory)
		{
			if(ItemQuantity < 0)
			{
				OwningInventory->RemoveItem(this);
			}
		}*/
	}
}

void UAGItemBase::Use(AAbyssalGuardiansCharacter* Character)
{
}
