// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterInteraction.h"

#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UMasterInteraction::UMasterInteraction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UMasterInteraction::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMasterInteraction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UMasterInteraction::addActor(APickup* actor, AActor* playerActor)
{
	AMainPaperCharacter* MainCharacter = Cast<AMainPaperCharacter>(playerActor);

	if (actor->canInteract == true)
	{

		if (MainCharacter)
		{
			//Array<APickup*> Interactables = MainCharacter->Interactables;
			MainCharacter->Interactables.Add(actor);

		}
	}
}

void UMasterInteraction::removeActor(APickup* actor, AActor* playerActor)
{
	AMainPaperCharacter* MainCharacter = Cast<AMainPaperCharacter>(playerActor);
	if (MainCharacter)
	{
		//Array<APickup*> Interactables = MainCharacter->Interactables;
		MainCharacter->Interactables.Remove(actor);

	}
}

