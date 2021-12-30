// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "PaperFlipbook.h"
#include "ActionItem.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class E_ActionItemType : uint8
{
	PRIMARY		UMETA(DisplayName = "Primary"),
	OFFHAND	UMETA(DisplayName = "Offhand"),
	HEAD	UMETA(DisplayName="Head"),
	CHEST	UMETA(DisplayName="Chest"),
	LEGS	UMETA(DisplayName = "Legs"),
	FEET	UMETA(DisplayName="Feet"),
	HAIR	UMETA(DisplayName="Hair")
};


USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ItemInfo")
	int32 Intelligence = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ItemInfo")
	int32 Strength = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ItemInfo")
	int32 Agility = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ItemInfo")
	int32 Damage = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ItemInfo")
	int32 Armor = 0;
};

USTRUCT(BlueprintType)
struct FAnimation
{
	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* WalkUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* IdleUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* RunUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* WalkLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* IdleLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* RunLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* WalkDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* IdleDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* RunDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* WalkRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* IdleRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* RunRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* AttackUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* AttackLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* AttackDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	UPaperFlipbook* AttackRight;
};



UCLASS()
class PIXEL3DGAME_API UActionItem : public UItem
{
	GENERATED_BODY()
	public:
	
	protected:
	virtual void Use(class AMainPaperCharacter* Character) override;
	virtual void Craft(class AMainPaperCharacter* Character) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Animation")
	FAnimation AnimationSlots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="ItemInfo")
	E_ActionItemType ActionItemType;
};
