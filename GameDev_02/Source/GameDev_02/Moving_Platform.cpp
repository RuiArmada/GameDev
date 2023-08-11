// Fill out your copyright notice in the Description page of Project Settings.


#include "Moving_Platform.h"

// Sets default values
AMoving_Platform::AMoving_Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoving_Platform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation(); // Sets the start location to the location of the platform when it starts moving
	
}

// Called every frame
void AMoving_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	
		1. Move platform forward
			- Get current location
			- Add vector to location
			- Set location
		2. Send platform back if 2 far
			- Check how far
			- Reverse direction of motion
	
	*/

	// ## 1. ##

	FVector CurrentLocation = GetActorLocation(); // Gets location of the platform

	CurrentLocation = CurrentLocation + (Velocity * DeltaTime); // Adds the velocity to the location, multiplied by DeltaTime to make it framerate independent

	SetActorLocation(CurrentLocation); // Sets the location of the platform to the new location

	// ## 2. ##

	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation); // Gets the distance between the start location and the current location

	if (DistanceMoved > MaxDistance) // Checks if the distance moved is greater than or equal to the maximum distance
	{

		FVector MoveDirection = Velocity.GetSafeNormal(); // Gets the direction of the velocity
		
		StartLocation = StartLocation + (MoveDirection * MaxDistance); // Sets the start location to the current location

		SetActorLocation(StartLocation); // Sets the location of the platform to the new start location

		Velocity = Velocity * -1; // Reverses the direction of the velocity
	}

}

