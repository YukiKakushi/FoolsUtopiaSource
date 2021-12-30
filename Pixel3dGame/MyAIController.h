// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL3DGAME_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

private:


	class UNavigationSystemV1* NavArea;
	
	UPROPERTY()
	FVector RandomLocation;


public:
	UFUNCTION()
		void RandomPatrol();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Voxel")
		class AVoxelWorld* VoxelWorld;

	virtual void OnPossess(APawn* ThisPawn) override;
};


