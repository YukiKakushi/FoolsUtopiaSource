// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPaperCharacter.h"
#include "VoxelCharacter.h"

#include "Enemy.generated.h"

UCLASS()
class PIXEL3DGAME_API AEnemy : public AVoxelCharacter
{
	GENERATED_BODY()

public:

	bool PlayerDetected;
	bool CanAttackPlayer;

	UPROPERTY(BlueprintReadWrite)
		bool CanDealDamage;
	
	class AMainPaperCharacter* PlayerRef;

	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerCollisionDetection;

	UPROPERTY(EditAnywhere)
		class USphereComponent* PlayerAttackCollisionDetection;

	//UPROPERTY(EditAnywhere)
	//	class UBoxComponent* DamageCollision;
	
	class AMyAIController* MyAIController;

		void OnAIMoveCompleted(struct FAIRequestID RequestID, const struct FPathFollowingResult& Result);

	UPROPERTY(EditAnywhere)
		float StoppingDistance= 100.0f;
	UPROPERTY(EditAnywhere)
		float EnemyDamage = 5.0f;
	UPROPERTY(EditAnywhere)
		float AttackSpeed = 1.0f;

	FTimerHandle SeekPlayerTimerHandle;
	FTimerHandle AttackTimerHandle;

	//UFUNCTION(BlueprintCallable, Category="AI")
		//void MoveCompleted();

	UFUNCTION()
		void MoveToPlayer();

	UFUNCTION()
		void SeekPlayer();

	UFUNCTION()
		void StopSeekingPlayer();

	UFUNCTION()
		void AttackPlayer();

	UFUNCTION()
		void OnPlayerDetectedOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnPlayerDetectedOverlapEnd(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UFUNCTION()
		void OnPlayerAttackOverlapBegin(class UPrimitiveComponent* OverlappedComp,
				class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
				int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnPlayerAttackOverlapEnd(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	// UFUNCTION()
	// 	void OnDealDamageOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	// 		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	// 		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	 void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
