// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item.h"
#include "Crafting.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCraftingUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL3DGAME_API UCrafting : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCrafting();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, Category = "Crafting")
	FOnInventoryUpdated FOnCraftingUpdated;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Crafting")
	TArray<TSubclassOf<UItem>> CraftableItems;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Crafting")
	TArray<UItem*> Craftables;

	UFUNCTION(BlueprintCallable)
	void InitUI();

	void CraftCheck(class AMainPaperCharacter* Character, UItem* ItemToCheck);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Crafting")
	TArray<UItem*> ItemsToRemove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Crafting")
	TArray<UItem*> ItemsToAdd;

	TArray<UItem*> tempRemoveItems;
	bool canCraft;
		
};
