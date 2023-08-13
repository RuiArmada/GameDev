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

private:

	UPROPERTY(EditAnywhere, Category="Moving") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	FVector MoveVelocity; // The velocity of the platform	

	UPROPERTY(EditAnywhere, Category = "Moving") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	float MaxDistance; // The maximum distance the platform will move

	UPROPERTY(EditAnywhere, Category = "Rotate") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	FRotator RotationVelocity; // The rate at which the platform will rotate
	
	UPROPERTY(VisibleAnywhere, Category = "Moving") // Tells UE that this variable needs to appear in blueprints, also, sets the variable in a costum category
	float DistanceMoved = 0; // The distance the platform has moved

	FVector StartLocation; // The location of the platform when it starts moving

	float GetDistanceMoved() const; // Function to get the distance the platform has moved

	bool SholdReturnPlatform() const; // If true, the platform will return to its start location

	void ProcessPlatformReturn(); // Function to process the platform returning to its start location

	void ProcessMovement(float DeltaTime); // Function to process the movement of the platform
		
	void MovePlatform(float DeltaTime); // Function to move the platform
	
	void RotatePlatform(float DeltaTime); // Function to rotate the platform
};
