// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

#include "MainPaperCharacter.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DialogueComponent = CreateDefaultSubobject<UDialogueComponent>(TEXT("Dialogue Component"));
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	CollisionSphere->SetRelativeScale3D(FVector(2.f,2.f,2.f));
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this,&ANPC::OnOverlapBegin);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &ANPC::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMainPaperCharacter* Character = Cast<AMainPaperCharacter>(OtherActor);
	if(Character)
	{
		CanSpeak = true;
		SelectedCharacter = Character;
		Character->NPC = this;
	}

}

void ANPC::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMainPaperCharacter* Character = Cast<AMainPaperCharacter>(OtherActor);
	if(Character)
	{
		CanSpeak = false;
		Character->NPC = nullptr;
	}
	SelectedCharacter->NPC = nullptr;
}



