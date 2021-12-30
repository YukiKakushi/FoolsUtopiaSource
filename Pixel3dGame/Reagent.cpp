// Fill out your copyright notice in the Description page of Project Settings.


#include "Reagent.h"

#include "MainPaperCharacter.h"

void UReagent::Use(AMainPaperCharacter* Character)
{
	if (Character)
	{
		//
	}
}

void UReagent::Craft(AMainPaperCharacter* Character)
{
	if (Character)
	{
		Character->CraftingComponent->CraftCheck(Character, this);
	}
}
