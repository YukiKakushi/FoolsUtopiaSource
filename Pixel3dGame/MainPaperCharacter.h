// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimationController.h"
#include "PaperCharacter.h"
#include "Pickup.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "Crafting.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "MainPaperCharacter.generated.h"

/**
 * 
 */


UCLASS()
class PIXEL3DGAME_API AMainPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
	


	public:
		AMainPaperCharacter();
		// Sets default values for this component's properties

	protected:


	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interactable")
		TArray<APickup*> Interactables;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float CurrentHealth;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float MaximumHealth;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float CurrentHunger;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float MaximumHunger;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float CurrentThirst;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
			float MaximumThirst;

		UFUNCTION(BlueprintCallable, Category = "Items")
			void UseItem(UItem* Item);

		UFUNCTION(BlueprintCallable, Category="Crafting")
			void CraftItem(UItem* Item);

		UFUNCTION(BlueprintCallable)
			void Pickup();
	
		UFUNCTION(BlueprintCallable)
			void AddToInventory(class UItem* Item);

		UFUNCTION(BlueprintCallable)
		void PerformAction(UPaperFlipbookComponent* ActionItem, E_Dir Direction, FVector RefLocation, UCameraComponent* Cam, USpringArmComponent* Spring);

		UFUNCTION()
		static void SetSpriteRotationOnCam(const float ZRotation,const float Zero,const float One,const float Two,const float Three, UPaperFlipbookComponent* ActionItem);
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
		class UInventoryComponent* InventoryComponent;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Crafting")
		class UCrafting* CraftingComponent;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Action")
		UPaperFlipbook* ActionItemAnimation;

		UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		AActor* NPC;

};


