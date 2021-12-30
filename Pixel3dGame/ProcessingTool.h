// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "ProcessingTool.generated.h"

UCLASS()
class PIXEL3DGAME_API AProcessingTool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcessingTool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
	TArray<TSubclassOf<UItem>> CraftableItems;

	TArray<UItem*> AddedCraftables;

	UFUNCTION(BlueprintCallable)
	void AddToCraftables(AMainPaperCharacter* Character);

	UFUNCTION(BlueprintCallable)
	void RemoveFromCraftables(AMainPaperCharacter* Character);

};
