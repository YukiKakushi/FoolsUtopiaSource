// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructible.generated.h"


UCLASS()
class PIXEL3DGAME_API ADestructible : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADestructible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 AmtOfLogs = 4;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UStaticMesh* LogMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UStaticMesh* LeavesMesh;

	UPROPERTY()
		UStaticMeshComponent* TreeMeshComponent;

	UPROPERTY()
		TArray<UStaticMeshComponent*> Logs;

	UPROPERTY()
		USceneComponent* RootObject;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool RandomHeight = true;
	
};
