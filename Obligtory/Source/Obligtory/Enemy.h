// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class OBLIGTORY_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	FVector CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*50.0f;
	
};
