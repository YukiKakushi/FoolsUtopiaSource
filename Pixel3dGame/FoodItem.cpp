// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "MainPaperCharacter.h"

void UFoodItem::Use(class AMainPaperCharacter* Character)
{
	if (Character)
	{
		if (Character->CurrentHealth <= Character->MaximumHealth - HealthToHeal)
		{
			Character->CurrentHealth += HealthToHeal;
			Character->CurrentHunger += HungerToHeal;
			Character->CurrentThirst += ThirstToHeal;
		}
	}
}

void UFoodItem::Craft(class AMainPaperCharacter* Character)
{
	
	if(Character)
	{
		Character->CraftingComponent->CraftCheck(Character, this);
	}
}