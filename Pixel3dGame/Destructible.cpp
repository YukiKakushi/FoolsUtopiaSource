// Fill out your copyright notice in the Description page of Project Settings.


#include "Destructible.h"

#include "VoxelUtilities/VoxelConsoleUtilities.h"


// Sets default values
ADestructible::ADestructible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");


}

// Called when the game starts or when spawned
void ADestructible::BeginPlay()
{
	
	Super::BeginPlay();
	if(RandomHeight)
	{
		AmtOfLogs = FMath::RandRange(4,10);
	}
	for(int i = 0; i < AmtOfLogs; i++)
	{
			UStaticMeshComponent* NewLog = NewObject<UStaticMeshComponent>(this);
			Logs.Add(NewLog);
			Logs[i]->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
			Logs[i]->RegisterComponent();
			Logs[i]->SetStaticMesh(LogMesh);
			Logs[i]->SetRelativeScale3D(FVector(0.8f,0.8f,0.8f));
			Logs[i]->CastShadow = true;
			Logs[i]->SetRelativeLocation(FVector(0.f, 0.f, 151.0f * i));
			
	}
	TreeMeshComponent = NewObject<UStaticMeshComponent>(this);
	TreeMeshComponent->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepWorldTransform);
	TreeMeshComponent->RegisterComponent();
	TreeMeshComponent->SetStaticMesh(LeavesMesh);
	TreeMeshComponent->CastShadow= true;
	TreeMeshComponent->SetRelativeScale3D(FVector(4.f,4.f,4.f));
	TreeMeshComponent->SetRelativeLocation(FVector(0.f,0.f,80.0f * Logs.Num()));
	UMaterialInstanceDynamic* MITree = UMaterialInstanceDynamic::Create(TreeMeshComponent->GetMaterial(0),this);
	MITree->SetScalarParameterValue(FName(TEXT("Speed")),FMath::RandRange(.05f,.1f));
	TreeMeshComponent->SetMaterial(0,MITree);
}

// Called every frame
void ADestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

