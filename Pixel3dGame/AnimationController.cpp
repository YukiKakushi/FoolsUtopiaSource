// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationController.h"


// Sets default values for this component's properties
UAnimationController::UAnimationController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAnimationController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAnimationController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAnimationController::Movement(APawn* pawnRef, AActor* actorRef, float rightamount, float upamount, E_AnimState& AnimState, E_Dir& Direction, bool AnimateStating, UPaperFlipbookComponent* Sprite)
{
		
	if (!AnimateStating)
	{
		
		if (upamount <= -.1f)
		{
			Direction = E_Dir::DOWN;
			pawnRef->AddMovementInput(Sprite->GetRightVector(), upamount * -1, false);
		}
		if (upamount >= .1f)
		{
			Direction = E_Dir::UP;
			pawnRef->AddMovementInput(Sprite->GetRightVector(), upamount * -1, false);
		}



		if (rightamount >= .3f)
		{
			Direction = E_Dir::RIGHT;
			pawnRef->AddMovementInput(Sprite->GetForwardVector(), rightamount, false);
		}
		if (rightamount <= -.3f)
		{
			Direction = E_Dir::LEFT;
			pawnRef->AddMovementInput(Sprite->GetForwardVector(), rightamount, false);
		}




		if (rightamount <= .5 && rightamount >= -.5 && upamount <= .5 && upamount >= -.5)
		{
			AnimState = E_AnimState::IDLE;
			
			/*
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Idle!"));
				*/
		}
		else {
			AnimState = E_AnimState::WALK;
			/*
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Walk!"));
			*/
		}
	}
}

void UAnimationController::Roll(APawn* pawnRef, AActor* actorRef, float force, E_AnimState& AnimState, E_Dir Direction, UCharacterMovementComponent* RollMovement, bool& AnimateStating, UPaperFlipbook* UpRoll, UPaperFlipbook* DownRoll,
	UPaperFlipbook* LeftRoll, UPaperFlipbook* RightRoll, UPaperFlipbookComponent* Sprite)
{	
	float rollMultiplier = 10000.0f;
	force = force * rollMultiplier;
	
	AnimState = E_AnimState::ROLL;
	AnimateStating = true;
	

	//RollMovement->AddForce(FVector(0.0f, force, 0.0f));
	
	switch(Direction)
	{
	case E_Dir::UP :
		RollMovement->AddForce(Sprite->GetRightVector() * force * -1);
		Sprite->SetFlipbook(UpRoll);
	break;
	
	case E_Dir::DOWN:
		RollMovement->AddForce(Sprite->GetRightVector() * force);
		Sprite->SetFlipbook(DownRoll);
	break;

	case E_Dir::LEFT:
		RollMovement->AddForce(Sprite->GetForwardVector() * force * -1);
		Sprite->SetFlipbook(LeftRoll);
	break;

	case E_Dir::RIGHT:
		RollMovement->AddForce(Sprite->GetForwardVector() * force);
		Sprite->SetFlipbook(RightRoll);
	break;
	
	}
}

void UAnimationController::Attack(APawn* pawnRef, AActor* actorRef, float force, E_AnimState& AnimState, E_Dir Direction, UCharacterMovementComponent* AttackMovement, bool& AnimateStating, UPaperFlipbook* UpAttack, UPaperFlipbook* DownAttack,
	UPaperFlipbook* LeftAttack, UPaperFlipbook* RightAttack, UPaperFlipbookComponent* Sprite)
{	
	float attackMultiplier = 10000.0f;
	force = force * attackMultiplier;
	
	AnimState = E_AnimState::ATTACK;
	AnimateStating = true;
	

	//RollMovement->AddForce(FVector(0.0f, force, 0.0f));
	
	switch(Direction)
	{
	case E_Dir::UP :
		AttackMovement->AddForce(Sprite->GetRightVector() * force * -1);
		Sprite->SetFlipbook(UpAttack);
		break;
	
	case E_Dir::DOWN:
		AttackMovement->AddForce(Sprite->GetRightVector() * force);
		Sprite->SetFlipbook(DownAttack);
		break;

	case E_Dir::LEFT:
		AttackMovement->AddForce(Sprite->GetForwardVector() * force * -1);
		Sprite->SetFlipbook(LeftAttack);
		break;

	case E_Dir::RIGHT:
		AttackMovement->AddForce(Sprite->GetForwardVector() * force);
		Sprite->SetFlipbook(RightAttack);
		break;
	
	}
	AttackMovement->DisableMovement();
}

void UAnimationController::AnimHandler(bool AnimateStating, E_AnimState AnimState, E_Dir Direction, UPaperFlipbookComponent* Sprite, bool Sprinting,
	UPaperFlipbook* UpWalk, UPaperFlipbook* UpIdle, UPaperFlipbook* UpSprint,
	UPaperFlipbook* LeftWalk, UPaperFlipbook* LeftIdle, UPaperFlipbook* LeftSprint,
	UPaperFlipbook* DownWalk, UPaperFlipbook* DownIdle, UPaperFlipbook* DownSprint,
	UPaperFlipbook* RightWalk, UPaperFlipbook* RightIdle, UPaperFlipbook* RightSprint)
{



	switch (Direction)
	{
		case E_Dir::UP:
			switch (AnimState)
			{
			case E_AnimState::WALK:
				if (!AnimateStating)
				{
					if (!Sprinting)
					{
						Sprite->SetFlipbook(UpWalk);
					}
					else {
						Sprite->SetFlipbook(UpSprint);
					}
				}
					break;
			case E_AnimState::IDLE:
				if (!AnimateStating)
				{
					Sprite->SetFlipbook(UpIdle);
				}
					break;
			}
			break;

		case E_Dir::DOWN:
			switch (AnimState)
			{
			case E_AnimState::WALK:
				if (!AnimateStating)
				{
					if (!Sprinting)
					{
						Sprite->SetFlipbook(DownWalk);
					}
					else {
						Sprite->SetFlipbook(DownSprint);
					}
				}
				break;
			case E_AnimState::IDLE:
				if (!AnimateStating)
				{
					Sprite->SetFlipbook(DownIdle);
				}
				break;
			}
			break;

		case E_Dir::LEFT:
			switch (AnimState)
			{
			case E_AnimState::WALK:
				if (!AnimateStating)
				{
					if (!Sprinting)
					{
						Sprite->SetFlipbook(LeftWalk);
					}
					else {
						Sprite->SetFlipbook(LeftSprint);
					}
				}
				break;
			case E_AnimState::IDLE:
				if (!AnimateStating)
				{
					Sprite->SetFlipbook(LeftIdle);
				}
				break;
			}
			break;

		case E_Dir::RIGHT:
			switch (AnimState)
			{
			case E_AnimState::WALK:
				if (!AnimateStating)
				{
					if (!Sprinting)
					{
						Sprite->SetFlipbook(RightWalk);
					}
					else {
						Sprite->SetFlipbook(RightSprint);
					}
				}
				break;
			case E_AnimState::IDLE:
				if (!AnimateStating)
				{
					Sprite->SetFlipbook(RightIdle);
				}
				break;
			}
			break;
	}
}

