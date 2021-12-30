// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL3DGAME_API UFoodItem : public UItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StatAfflictions", meta = (ClampMin = 0.0))
		float HealthToHeal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StatAfflictions", meta = (ClampMin = 0.0))
		float HungerToHeal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StatAfflictions", meta = (ClampMin = 0.0))
		float ThirstToHeal;
	
protected:

	virtual void Use(class AMainPaperCharacter* Character) override;
	virtual void Craft(class AMainPaperCharacter* Character) override;
	
	
	///void OnUse(AMainPaperCharacter* Character) override;

};
