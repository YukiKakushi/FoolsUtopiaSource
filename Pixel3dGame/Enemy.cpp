// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AITypes.h"
#include "MyAIController.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	PlayerCollisionDetection = CreateDefaultSubobject<USphereComponent>(TEXT("Player Collision Detection"));
	PlayerCollisionDetection->SetupAttachment(RootComponent);

	PlayerAttackCollisionDetection = CreateDefaultSubobject<USphereComponent>(TEXT("Player Attack Collision Detection"));
	PlayerAttackCollisionDetection->SetupAttachment(RootComponent);
	
}


// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	MyAIController = Cast<AMyAIController>(GetController());

	if(MyAIController)
	{
		if (MyAIController->GetPathFollowingComponent())

			MyAIController->GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &AEnemy::OnAIMoveCompleted);	
	}

	PlayerCollisionDetection->OnComponentBeginOverlap.AddDynamic(this,
	&AEnemy::OnPlayerDetectedOverlapBegin);

	PlayerCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&AEnemy::OnPlayerDetectedOverlapEnd);

	PlayerAttackCollisionDetection->OnComponentBeginOverlap.AddDynamic(this,
		&AEnemy::OnPlayerAttackOverlapBegin);
	
	PlayerAttackCollisionDetection->OnComponentEndOverlap.AddDynamic(this,
		&AEnemy::OnPlayerAttackOverlapEnd);

	//DamageCollision->OnComponentBeginOverlap.AddDynamic(this,
	//	&AEnemy::OnDealDamageOverlapBegin);

	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnAIMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	
	if (!PlayerDetected)
	{
		if(MyAIController)
		{
			MyAIController->RandomPatrol();
			/*
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Can't attack player %hs"), CanAttackPlayer ? "Yes" : "No"));
			*/
		}
	}
	else if (PlayerDetected && CanAttackPlayer)
	{
		StopSeekingPlayer();
		AttackPlayer();

		// attack player
		/*
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Player Attacked")));
		*/
	}
}

void AEnemy::MoveToPlayer()
{
	if(MyAIController)
	{
		if (PlayerRef)
		{
			MyAIController->MoveToLocation(PlayerRef->GetActorLocation(), StoppingDistance, true);

			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("MoveToPlayer")));
		}
	}

}
	
void AEnemy::SeekPlayer()
{
	//
	if (CanAttackPlayer != true)
	{
		MoveToPlayer();
	}
	
	GetWorld()->GetTimerManager().SetTimer(SeekPlayerTimerHandle, this, &AEnemy::SeekPlayer, 0.25f, true);

	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("SeekPlayer")));
}

void AEnemy::StopSeekingPlayer()
{
	//
	GetWorld()->GetTimerManager().ClearTimer(SeekPlayerTimerHandle);
	
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Stop Seeking Player")));
	
}

void AEnemy::AttackPlayer()
{
	if(PlayerRef)
	{
		if(CanAttackPlayer == true)
		{
			// Dealing Damage to player
			PlayerRef->CurrentHealth = (PlayerRef->CurrentHealth - EnemyDamage);
		}
	}
	// Timer for AttackSpeed
	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &AEnemy::AttackPlayer, AttackSpeed, true);
}

void AEnemy::OnPlayerDetectedOverlapBegin(class UPrimitiveComponent* OverlappedComp,
                                          class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
                                          int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//
	PlayerRef = Cast<AMainPaperCharacter>(OtherActor);
	if (PlayerRef)
	{
		//
		PlayerDetected = true;
		SeekPlayer();
	}
}

void AEnemy::OnPlayerDetectedOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// if overlap ends get Main Character Ref
	PlayerRef = Cast<AMainPaperCharacter>(OtherActor);

	if(MyAIController)
	{
		if (PlayerRef)
		{
			// set to can't attack the player and stop seeking player
			CanAttackPlayer = false;
			PlayerDetected = false;
			StopSeekingPlayer();
			MyAIController->RandomPatrol();
		
		}
	}

}

void AEnemy::OnPlayerAttackOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerRef = Cast<AMainPaperCharacter>(OtherActor);
	if (PlayerRef)
	{
		CanAttackPlayer = true;
		//attack player
	}
}

void AEnemy::OnPlayerAttackOverlapEnd(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//
	PlayerRef = Cast<AMainPaperCharacter>(OtherActor);
	if (PlayerRef)
	{
		CanAttackPlayer = false;

		SeekPlayer();
	}
}

//void AEnemy::OnDealDamageOverlapBegin(UPrimitiveComponent* OverlappedComp,
//	AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
	// PlayerRef = Cast<AMainPaperCharacter>(OtherActor);
	// if (PlayerRef && CanDealDamage)
	// {
	// 	// deal damage to player
	// 	if (GEngine)
	// 		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Damage Collision")));
	// }
//}