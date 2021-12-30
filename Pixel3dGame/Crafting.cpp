// Fill out your copyright notice in the Description page of Project Settings.


#include "Crafting.h"

#include "MainPaperCharacter.h"

// Sets default values for this component's properties
UCrafting::UCrafting()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCrafting::BeginPlay()
{
	Super::BeginPlay();

}

void UCrafting::InitUI()
{
	for(int i = 0; i < CraftableItems.Num(); i++)
	{
		if(CraftableItems[i])
		{
			UItem* CraftToAdd = NewObject<UItem>(GetParentNativeClass(CraftableItems[i]), CraftableItems[i]);
			if(CraftToAdd)
			Craftables.Add(CraftToAdd);
		}
	}
}

void UCrafting::CraftCheck(class AMainPaperCharacter* Character, UItem* ItemToCheck)
{
	canCraft = true;
	if(Character)
	{
		ItemsToRemove.Empty();
		ItemsToAdd.Empty();
		int amtToRemove = 0;
		
		//Loop through Reagents on item
		for(FCraftingReagent CraftingItem :  ItemToCheck->CraftingReagents)
		{
			for(int x = 0; x < CraftingItem.RequiredAmt; x++)
			{
				amtToRemove += 1;
			}

			//Loop through Inventory
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Starting Inventory Search...")));

			bool reagentsAdded = false;
			for(UItem* InventoryItem : Character->InventoryComponent->Items)
			{
				
				if(InventoryItem)
				{
					//if Reagent is = Item in Inventory
					if(CraftingItem.Reagent == InventoryItem->GetClass())
					{
						if(InventoryItem->Amt <= 0)
						{
							break;
						}

						CraftingItem.AmountCounted += InventoryItem->Amt;

						if(CraftingItem.AmountCounted >= CraftingItem.RequiredAmt)
						{
							//Add to Items to Remove for Each in stack
							for(int x = 0; x < CraftingItem.RequiredAmt; x++)
							{
								ItemsToRemove.Add(InventoryItem);
							}
							reagentsAdded = true;
						}
						
						if(reagentsAdded)
						{
							reagentsAdded = false;
							break;
						}
						
					}
				}
			}

			if(CraftingItem.AmountCounted < CraftingItem.RequiredAmt)
			{
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("required amount:%d"), CraftingItem.RequiredAmt));
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("amount counted:%d"), CraftingItem.AmountCounted));

				canCraft = false;
			}
		}

		if(canCraft == true)
		{
			for(UItem* ItemToRemove : ItemsToRemove)
			{
				if(ItemToRemove)
				{
					Character->InventoryComponent->RemoveItem(ItemToRemove);
				}
			}
			for(int i = 0; i < ItemToCheck->AmountToCraft; i++)
			{
				Character->AddToInventory(ItemToCheck);
				//Character->InventoryComponent->AddItem(ItemToCheck);
			}
		}
		for(FCraftingReagent CraftingItem :  ItemToCheck->CraftingReagents)
		{
			CraftingItem.AmountCounted = 0;
		}
		
		canCraft = false;
	}
	ItemsToRemove.Empty();
}



// Called every frame
void UCrafting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
