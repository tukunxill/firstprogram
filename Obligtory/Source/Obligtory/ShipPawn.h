// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ShipPawn.generated.h"

UCLASS()
class OBLIGTORY_API AShipPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void Move_YAxis(float AxisValue);

	void Shoot();

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		AActor* CameraOne = nullptr;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABullet> Bullet_BP;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemy> Enemy_BP;



	FVector CurrentVelocity;

	const int max_Y = 450;

	const int max_X = 150;

	const int positionIncrement = 100;
};