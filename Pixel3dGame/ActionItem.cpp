// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionItem.h"
#include "MainPaperCharacter.h"

void UActionItem::Use(AMainPaperCharacter* Character)
{
	if(Character)
	{
		
	}
}

void UActionItem::Craft(AMainPaperCharacter* Character)
{
	if(Character)
	{
		Character->CraftingComponent->CraftCheck(Character, this);
	}
}
