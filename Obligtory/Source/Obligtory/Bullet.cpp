// Fill out your copyright notice in the Description page of Project Settings.

#include "Obligtory.h"
#include "Bullet.h"
#include "Enemy.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Bullet Spawned"));

	CollisionBox = this->FindComponentByClass<USphereComponent>();

	if (CollisionBox) {
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I need a collider you lazy bum!"));
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	FVector Destruction = GetActorLocation();

	if (Destruction.X >= 400.0f)
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destruction"));
	}
}
	void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) 
	{
		if (OtherActor->IsA(AEnemy::StaticClass())) {
			OtherActor->Destroy();
			Destroy();
		}

	}

