// Fill out your copyright notice in the Description page of Project Settings.

#include "Obligtory.h"
#include "ShipPawn.h"
#include "Bullet.h"
#include "Enemy.h"


// Sets default values
AShipPawn::AShipPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AShipPawn::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->SetViewTarget(CameraOne);

	UWorld* World = GetWorld();

	FVector EnemyLocation = FVector(1.0f, -300.0f, 1.0f);

	if (World)
	{
		for (int i = -450; i <= max_Y; i += positionIncrement)
		{
			for (int j = -150; j <= max_X; j += positionIncrement)
			{
				EnemyLocation = FVector(j, i, 40.0f); //Dette er sannsynligvis ikke den lureste for-loopen, men den funker

				World->SpawnActor<AEnemy>(Enemy_BP, EnemyLocation, FRotator::ZeroRotator);
			}
		}
	}
}

// Called every frame
void AShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void AShipPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveY", this, &AShipPawn::Move_YAxis);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AShipPawn::Shoot);

}

void AShipPawn::Move_YAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -2.0f, 2.0f)*200.0f;
}

void AShipPawn::Shoot()
{
	UWorld* World = GetWorld();

	if (World)
	{
		FVector Location = GetActorLocation();

		World->SpawnActor<ABullet>(Bullet_BP, Location, FRotator::ZeroRotator);
	}

}