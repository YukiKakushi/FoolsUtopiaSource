// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPaperCharacter.h"

#include "DrawDebugHelpers.h"
#include "PaperFlipbookComponent.h"
#include "InventoryComponent.h"

// Called when the game starts
AMainPaperCharacter::AMainPaperCharacter()
{
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory Component"));
	CraftingComponent = CreateDefaultSubobject<UCrafting>(TEXT("Crafting Component"));
}

void AMainPaperCharacter::UseItem(class UItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this);
	}
}

void AMainPaperCharacter::CraftItem(class UItem* Item)
{
	if(Item)
	{
		Item->Craft(this);
		Item->OnCraft(this);
	}
}

void AMainPaperCharacter::Pickup()
{
	bool foundStack = false;

		if (Interactables.Num() > 0)
		{
			//Scan through the inventory
			for(int i = 0; i < InventoryComponent->Items.Num(); i++)
			{
				//if Item class is the same as the interactable class being picked up
				if(InventoryComponent->Items[i]->GUID == Interactables[0]->ItemGUID && InventoryComponent->Items[i]->Amt < InventoryComponent->Items[i]->StackSize)
				{
					//Found a stack and increase the stack size.	
					InventoryComponent->Items[i]->Amt += 1;
					foundStack = true;
					
					//if (GEngine)
					//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Found a stack!"));
				}
				
			}
			if(foundStack == false)
			{
				//Add Item to Inventory
				UItem* newItem = NewObject<UItem>(GetParentNativeClass(Interactables[0]->itemClass), Interactables[0]->itemClass);
				InventoryComponent->AddItem(newItem);
			}
			
			Interactables[0]->SetActorHiddenInGame(true);
			Interactables[0]->canInteract = false;
			
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Pickedup!") + Interactables[0]->GetName());
		}


	}
void AMainPaperCharacter::PerformAction(UPaperFlipbookComponent* ActionItem, E_Dir Direction, FVector RefLocation,UCameraComponent* Cam, USpringArmComponent* Spring)
{
	if(ActionItem)
	{
		//if(GEngine)
			//GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString(TEXT("FlipbookSet")));
	}
	/*
	ActionItem->SetVisibility(true);
	if(ActionItemAnimation)
	{
		FVector ActorLoc;
		FVector Offset;
		FVector NewLocation;
		FVector VerticalOffset = FVector(0.0f,0.0f, 20.0f);
		float SpringZ = 0.0f;
		ActionItem->SetPlayRate(1.0f);
		ActionItem->SetPlaybackPositionInFrames(1, true);
		ActionItem->SetFlipbook(ActionItemAnimation);
		FVector End;
		FHitResult Hit(ForceInit);


		
		switch(Direction)
		{
		case E_Dir::UP:
			Offset = Cam->GetForwardVector() * 40;
			NewLocation = RefLocation + Offset + VerticalOffset;
			ActionItem->SetWorldLocation(NewLocation);
			SpringZ = Spring->GetRelativeRotation().Yaw;
			SetSpriteRotationOnCam(SpringZ, 90,0,-90,-180,ActionItem);

			End = ActorLoc + (GetActorForwardVector() * -70.f);
			ActorLoc = GetActorLocation();
			DrawDebugLine(GetWorld(),ActorLoc,End,FColor::Green,true,2.f,false,4.f);
			GetWorld()->LineTraceSingleByChannel(Hit,ActorLoc,End,ECC_WorldDynamic);
			
			break;
			
		case E_Dir::DOWN:
			Offset = Cam->GetForwardVector() * -40;
			NewLocation = RefLocation + Offset + VerticalOffset;
			ActionItem->SetWorldLocation(NewLocation);
			SpringZ = Spring->GetRelativeRotation().Yaw;
			SetSpriteRotationOnCam(SpringZ, -90,-180,90,0,ActionItem);

			End = ActorLoc + (GetActorForwardVector() * 70.f);
			ActorLoc = GetActorLocation();
			DrawDebugLine(GetWorld(),ActorLoc,End,FColor::Green,true,2.f,false,4.f);
			GetWorld()->LineTraceSingleByChannel(Hit,ActorLoc,End,ECC_WorldDynamic);
			break;

		case E_Dir::LEFT:
			Offset = Cam->GetRightVector() * -40;
			NewLocation = RefLocation + Offset + VerticalOffset;
			ActionItem->SetWorldLocation(NewLocation);
			SpringZ = Spring->GetRelativeRotation().Yaw;
			SetSpriteRotationOnCam(SpringZ, 0,-90,-180,90,ActionItem);
			break;

		case E_Dir::RIGHT:
			Offset = Cam->GetRightVector() * 40;
			NewLocation = RefLocation + Offset + VerticalOffset;
			ActionItem->SetWorldLocation(NewLocation);
			SpringZ = Spring->GetRelativeRotation().Yaw;
			SetSpriteRotationOnCam(SpringZ, 180,90,0,-90,ActionItem);
			break;

		case E_Dir::NONE:
			break;
		}
		//if(GEngine)
			//GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::Printf(TEXT("Vector Rotation Z : %f"),SpringZ));
	}*/
}

void AMainPaperCharacter::SetSpriteRotationOnCam(const float ZRotation,const float Zero,const float One,const float Two,const float Three, UPaperFlipbookComponent* ActionItem)
{
	if(ZRotation < 10 && ZRotation > -10) //Cam Facing Initial Right
	{
		FRotator NewRotator;
		NewRotator.Roll = -90;
		NewRotator.Pitch = 0;
		NewRotator.Yaw = Zero;
		ActionItem->SetRelativeRotation(NewRotator);

		
	}
	if((ZRotation > -100 && ZRotation < -80) || (ZRotation > 260 && ZRotation < 280)) //Cam Facing Initial Forward
	{
		FRotator NewRotator;
		NewRotator.Roll = -90;
		NewRotator.Pitch = 0;
		NewRotator.Yaw = One;
		ActionItem->SetRelativeRotation(NewRotator);
	}
	if((ZRotation > -190 && ZRotation < -170) || (ZRotation > 170 && ZRotation < 190)) //Cam Facing Initial Left
	{
		FRotator NewRotator;
		NewRotator.Roll = -90;
		NewRotator.Pitch = 0;
		NewRotator.Yaw = Two;
		ActionItem->SetRelativeRotation(NewRotator);
	}
	if(ZRotation > 80 && ZRotation < 100) //Cam Facing Initial Back
	{
		FRotator NewRotator;
		NewRotator.Roll = -90;
		NewRotator.Pitch = 0;
		NewRotator.Yaw = Three;
		ActionItem->SetRelativeRotation(NewRotator);
	}
	
}


void AMainPaperCharacter::AddToInventory(class UItem* Item)
{
	bool foundStack = false;
	if (InventoryComponent->Items.Num() != 0)
	{

		/*Insert logic to remove craft reagent requirements, dont add if they dont exist*/
		//Scan through the inventory
		for(int i = 0; i < InventoryComponent->Items.Num(); i++)
		{
			//if Item class is the same as the interactable class being picked up
			if(InventoryComponent->Items[i]->GUID == Item->GUID && InventoryComponent->Items[i]->Amt < InventoryComponent->Items[i]->StackSize)
			{
				//Found a stack and increase the stack size.	
				InventoryComponent->Items[i]->Amt += 1;
				foundStack = true;
				//if (GEngine)
				//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Found a stack!"));
			}
		}
	}
				
		
		if(foundStack == false)
		{
			//Add Item to Inventory
			InventoryComponent->AddItem(Item);
		}
	

}


