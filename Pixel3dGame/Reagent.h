// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Reagent.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL3DGAME_API UReagent : public UItem
{
	GENERATED_BODY()

public:
	

protected:
	virtual void Use(class AMainPaperCharacter* Character) override;
	virtual void Craft(class AMainPaperCharacter* Character) override;
	
};

