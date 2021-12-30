// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAi.h"

// Sets default values
AEnemyAi::AEnemyAi()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

