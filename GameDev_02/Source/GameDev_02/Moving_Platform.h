// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moving_Platform.generated.h"

UCLASS()
class GAMEDEV_02_API AMoving_Platform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoving_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Moving Platform") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	FVector Velocity; // The velocity of the platform	

	UPROPERTY(EditAnywhere, Category = "Moving Platform") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	float MaxDistance; // The maximum distance the platform will move

	UPROPERTY(VisibleAnywhere, Category = "Moving Platform") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	float DistanceMoved = 0; // The distance the platform has moved

	FVector StartLocation; // The location of the platform when it starts moving
	
};
