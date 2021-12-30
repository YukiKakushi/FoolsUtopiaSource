// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"


#include "Pickup.generated.h"


UCLASS()
class PIXEL3DGAME_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:


public:	

	bool canInteract = true;
    //UClass* itemclass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Items")
	int32 ItemGUID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Items")
	TSubclassOf<UItem> itemClass;
};
