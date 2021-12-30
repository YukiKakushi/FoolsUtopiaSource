// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildableItem.h"
#include "MainPaperCharacter.h"

void UBuildableItem::Use(class AMainPaperCharacter* Character)
{
	if(Character)
	{
		FVector CharacterLocation = Character->GetActorLocation();
		FVector Offset = FVector(0,200,0);
		FVector SpawnLocation = CharacterLocation + Offset;
		const FRotator SpawnRotation = FRotator(0,0,0);
		FActorSpawnParameters SpawnInfo;
		UWorld* WorldPtr = GetWorld();
		
		Character->GetWorld()->SpawnActor<AProcessingTool>(ToolToConstruct, SpawnLocation, SpawnRotation, SpawnInfo);
		
		
	}
}

void UBuildableItem::Craft(class AMainPaperCharacter* Character)
{
	if(Character)
	{
		Character->CraftingComponent->CraftCheck(Character, this);
	}
}