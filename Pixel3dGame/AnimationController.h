// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "PaperFlipbookComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "AnimationController.generated.h"


UENUM(BlueprintType)
enum class E_AnimState : uint8
{
	IDLE	UMETA(DisplayName = "Idle"),
	WALK	UMETA(DisplayName = "Walk"),
	ROLL	UMETA(DisplayName = "Roll"),
	ATTACK UMETA(DisplayName = "Attack"),
	NONE	UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class E_Dir : uint8
{
	UP		UMETA(DisplayName = "Up"),
	DOWN	UMETA(DisplayName = "Down"),
	LEFT	UMETA(DisplayName="Left"),
	RIGHT	UMETA(DisplayName="Right"),
	NONE	UMETA(DisplayName = "None")
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL3DGAME_API UAnimationController : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UAnimationController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable)
	void Movement( APawn* pawnRef, AActor* actorRef, float rightamount, float upamount, E_AnimState& AnimState, E_Dir& Direction, bool AnimateStating, UPaperFlipbookComponent* Sprite);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = 2))
		void Roll (APawn* pawnRef, AActor* actorRef, float force, E_AnimState& AnimState, E_Dir Direction, UCharacterMovementComponent* RollMovement, bool& AnimateStating,UPaperFlipbook* UpRoll, UPaperFlipbook* DownRoll,
			UPaperFlipbook* LeftRoll, UPaperFlipbook* RightRoll, UPaperFlipbookComponent* Sprite);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = 2))
	void Attack (APawn* pawnRef, AActor* actorRef, float force, E_AnimState& AnimState, E_Dir Direction, UCharacterMovementComponent* AttackMovement, bool& AnimateStating,UPaperFlipbook* UpAttack, UPaperFlipbook* DownAttack,
		UPaperFlipbook* LeftAttack, UPaperFlipbook* RightAttack, UPaperFlipbookComponent* Sprite);

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	class UPaperFlipbookComponent* Sprite;

	UFUNCTION(BlueprintCallable, meta=(AdvancedDisplay = 2))
	void AnimHandler(bool AnimateStating, E_AnimState AnimState, E_Dir Direction, UPaperFlipbookComponent* Sprite, bool Sprinting,
		UPaperFlipbook* UpWalk, UPaperFlipbook* UpIdle, UPaperFlipbook* UpSprint,
		UPaperFlipbook* LeftWalk, UPaperFlipbook* LeftIdle, UPaperFlipbook* LeftSprint,
		UPaperFlipbook* DownWalk, UPaperFlipbook* DownIdle, UPaperFlipbook* DownSprint,
		UPaperFlipbook* RightWalk, UPaperFlipbook* RightIdle,UPaperFlipbook* RightSprint);

		
};
