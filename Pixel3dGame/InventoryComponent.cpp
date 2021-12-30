// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Item.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Capacity = 20;
	// ...
}	


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::AddItem(UItem* Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Returned false!"));
		return false;
	}
	
	//Item->OwningInventory = this;
	Items.Add(Item);
	OnInventoryUpdated.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{

	bool canRemove = true;
	if (Item)
	{
		//Scan through the inventory
		for(int i = 0; i < Items.Num(); i++)
		{
			//if Item class is the same as the interactable class being picked up
			if(Items[i]->GUID == Item->GUID)
			{
				//Found a stack and increase the stack size.
				if(Items[i]->Amt > 1 )
				{
					canRemove = false;
				}
				if(!canRemove)
				Items[i]->Amt -= 1;
				if(Items[i]->Amt <= 0)
				{
					Items.RemoveSingle(Items[i]);
				}
				//if (GEngine)
				//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Found a stack!"));
			}
				
		}
		if(canRemove)
		{
			//Add Item to Inventory
			Items.RemoveSingle(Item);
		}

		
		
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}

