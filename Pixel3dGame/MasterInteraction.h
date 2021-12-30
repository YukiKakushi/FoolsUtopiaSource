// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "MainPaperCharacter.h"
#include "MasterInteraction.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL3DGAME_API UMasterInteraction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMasterInteraction();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void addActor(APickup* actor, AActor* playerActor);
	
	UFUNCTION(BlueprintCallable)
	void removeActor(APickup* actor, AActor* playerActor);


};
