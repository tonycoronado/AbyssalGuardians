#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemDataStructs.generated.h" //must be the last include ever

UENUM()
enum class EItemQuality : uint8
{
	Common UMETA(DisplayName = "Common"),
	Uncommon UMETA(DisplayName = "Uncommon"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
	Mythic UMETA(DisplayName = "Mythic")
};

UENUM()
enum class EItemType : uint8
{
	Weapon UMETA(DisplayName = "Weapon"),
	Tool UMETA(DisplayName = "Tool"),
	Armor UMETA(DisplayName = "Armor"),
	Support UMETA(DisplayName = "Support"),
	Shield UMETA(DisplayName = "Shield"),
	Upgrade UMETA(DisplayName = "Upgrade"),
	Consumable UMETA(DisplayName = "Consumable"),
	Material UMETA(DisplayName = "Material"),
	Quest UMETA(DisplayName = "Quest"),
	Toy UMETA(DisplayName = "Toy"),
	Mundane UMETA(DisplayName = "Mundane")
};

USTRUCT()
struct FItemStatistics
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	float ArmorRating;

	UPROPERTY(EditAnywhere)
	float DamageValue;

	UPROPERTY(EditAnywhere)
	float RestorationAmount;

	UPROPERTY(EditAnywhere)
	float SellValue;
};

USTRUCT()
struct FItemTextData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	FText Name;
	
	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere)
	FText InteractionText;

	UPROPERTY(EditAnywhere)
	FText UsageText;
	
};

USTRUCT()
struct FItemNumericData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	float Weight;

	UPROPERTY(EditAnywhere)
	int32 MaxStackSize;

	UPROPERTY(EditAnywhere)
	bool bIsStackable;

};

USTRUCT()
struct FItemAssetData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;
};

USTRUCT()
struct FItemData : public FTableRowBase //inherits from FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//Here I am adding an instance of everything that is up

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
};
