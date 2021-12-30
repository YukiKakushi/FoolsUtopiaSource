// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueComponent.h"
#include "MainPaperCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "NPC.generated.h"

UCLASS()
class PIXEL3DGAME_API ANPC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPC();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDialogueComponent* DialogueComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	USphereComponent* CollisionSphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	AMainPaperCharacter* SelectedCharacter;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	bool CanSpeak;
};
