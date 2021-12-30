// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryComponent.h"

#include "Item.generated.h"

class UItem;
USTRUCT(BlueprintType)
struct FCraftingReagent
{
	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
	int32 RequiredAmt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
	TSubclassOf<UItem> Reagent;
	
	FCraftingReagent()
	{
		RequiredAmt = 1;
	}

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Crafting")
	int32 GUID;

	UPROPERTY()
	int32 AmountCounted = 0;
};

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)

class PIXEL3DGAME_API UItem : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UItem();

	//virtual class UWorld* GetWorld() const { return World; }

protected:


public:	

	//UPROPERTY(Transient)
	//	class UWorld* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
		int32 AmountToCraft = 1;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText UseActionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		class UTexture2D* Thumbnail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
		int32 Amt;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Item")
		int32 StackSize;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ID")
		int32 GUID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Crafting")
	TArray<FCraftingReagent> CraftingReagents;



	UPROPERTY()
		class UInventoryComponent* OwningInventory;

	UPROPERTY()
		class UCrafting* CraftingWindow;

	virtual void Use(class AMainPaperCharacter* Character) PURE_VIRTUAL(UItem, );
	virtual void Craft(class AMainPaperCharacter* Character) PURE_VIRTUAL(UItem, );

	UFUNCTION(BlueprintImplementableEvent)
		void OnUse(class AMainPaperCharacter* Character);

	UFUNCTION(BlueprintImplementableEvent)
		void OnCraft(class AMainPaperCharacter* Character);

};
