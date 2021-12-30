// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcessingTool.h"

#include "MainPaperCharacter.h"

// Sets default values
AProcessingTool::AProcessingTool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProcessingTool::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProcessingTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProcessingTool::AddToCraftables(AMainPaperCharacter* Character)
{
	if(Character)
	{
		for(int i =0; i < CraftableItems.Num(); i++)
		{
			FString Name = CraftableItems[i]->GetClass()->GetDefaultObject()->GetName();
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, Name);
			UItem* newCraftable = NewObject<UItem>(GetParentNativeClass(CraftableItems[i]), CraftableItems[i]);
			Character->CraftingComponent->Craftables.Add(newCraftable);
			Character->CraftingComponent->CraftableItems.Add(CraftableItems[i]);
			AddedCraftables.Add(newCraftable);
		}
	}
}

void AProcessingTool::RemoveFromCraftables(AMainPaperCharacter* Character)
{
	if(Character)
	{
		for(int i =0; i < CraftableItems.Num(); i++)
		{
			Character->CraftingComponent->CraftableItems.Remove(CraftableItems[i]);
		}
		for(UItem* AddedCraftable : AddedCraftables)
		{
			Character->CraftingComponent->Craftables.Remove(AddedCraftable);
		}
		AddedCraftables.Empty();
	}
}

