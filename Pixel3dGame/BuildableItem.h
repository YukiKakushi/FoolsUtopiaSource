// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ProcessingTool.h"
#include "BuildableItem.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL3DGAME_API UBuildableItem : public UItem
{
	GENERATED_BODY()

protected:
	virtual void Use(class AMainPaperCharacter* Character) override;
	virtual void Craft(class AMainPaperCharacter* Character) override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AProcessingTool> ToolToConstruct;
};
