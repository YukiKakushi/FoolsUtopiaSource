// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

#include "Enemy.h"
#include "EngineUtils.h"
#include "NavigationSystem.h"
#include "VoxelWorld.h"
#include "Kismet/GameplayStatics.h"


void AMyAIController::BeginPlay()
{
	//
	Super::BeginPlay();
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
}

void AMyAIController::RandomPatrol()
{
	//

		if(GetWorld() && this)
		{
			if (NavArea)
			{
				NavArea->K2_GetRandomReachablePointInRadius(GetWorld(),GetPawn()->GetActorLocation(), RandomLocation,500.0f);
				MoveToLocation(RandomLocation, 5.0f,false,false, true);
			}
		
		}
}


void AMyAIController::OnPossess(APawn* ThisPawn)
{
	Super::OnPossess(ThisPawn);
		RandomPatrol();
	
}

