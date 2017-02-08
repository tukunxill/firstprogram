// Fill out your copyright notice in the Description page of Project Settings.

#include "Obligtory.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Enemy Spawned"));

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() - (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	FVector Destruction = GetActorLocation();

	if (Destruction.X <= -730.0f)
	{
		CurrentVelocity = FVector(-1.0f, 0.0f, 0.0f) * 300.0f;
	}

	if (Destruction.X >= 160.0f) 
	{

		CurrentVelocity = FVector(1.0f, 0.0f, 0.0f) * 300.0f;
	}
}