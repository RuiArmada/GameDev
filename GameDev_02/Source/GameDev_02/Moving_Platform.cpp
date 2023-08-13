// Fill out your copyright notice in the Description page of Project Settings.


#include "Moving_Platform.h"

AMoving_Platform::AMoving_Platform() // Sets default values
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AMoving_Platform::BeginPlay() // Called when the game starts or when spawned
{
	Super::BeginPlay();

	StartLocation = GetActorLocation(); // Sets the start location to the location of the platform when it starts moving

	FString Name = GetName(); // Gets the name of the platform

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name); // Logs the name of the platform to the console	
}


float AMoving_Platform::GetDistanceMoved() const // Function to get the distance the platform has moved
{

	FVector CurrentLocation = GetActorLocation(); // Gets the current location of the platform

	return FVector::Dist(StartLocation, CurrentLocation); // Returns the distance moved
}


bool AMoving_Platform::SholdReturnPlatform() const // Function to check if the platform should return to its start location
{

	return GetDistanceMoved() > MaxDistance; // Returns true if the distance moved is greater than the maximum distance
}


void AMoving_Platform::ProcessPlatformReturn() // Function to process the platform returning to its start location
{

	float OverShoot = DistanceMoved - MaxDistance; // Calculates the overshoot

	FString Name = GetName(); // Gets the name of the platform

	UE_LOG(LogTemp, Display, TEXT("%s Platform Overshoot by: %f"), *Name, OverShoot); // Logs the overshoot to the console

	FVector MoveDirection = MoveVelocity.GetSafeNormal(); // Gets the direction of the velocity

	StartLocation = StartLocation + (MoveDirection * MaxDistance); // Sets the start location to the current location

	SetActorLocation(StartLocation); // Sets the location of the platform to the new start location

	MoveVelocity = MoveVelocity * -1; // Reverses the direction of the velocity
}


void AMoving_Platform::ProcessMovement(float DeltaTime) // Function to process the movement of the platform
{

	FVector CurrentLocation = GetActorLocation(); // Gets location of the platform

	CurrentLocation = CurrentLocation + (MoveVelocity * DeltaTime); // Adds the velocity to the location, multiplied by DeltaTime to make it framerate independent

	SetActorLocation(CurrentLocation); // Sets the location of the platform to the new location
}


void AMoving_Platform::MovePlatform(float DeltaTime) // Function to move the platform
{

	if (SholdReturnPlatform()) // Checks if the distance moved is greater than or equal to the maximum distance
	{

		ProcessPlatformReturn(); // Calls the ProcessPlatformReturn function
		
	} else {

		ProcessMovement(DeltaTime); // Calls the ProcessMovement function

	}
}


void AMoving_Platform::RotatePlatform(float DeltaTime) // Function to rotate the platform
{

	AddActorLocalRotation(RotationVelocity * DeltaTime); // Adds the rotation velocity to the current rotation, multiplied by DeltaTime to make it framerate independent
}


void AMoving_Platform::Tick(float DeltaTime) // Called every frame
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime); // Calls the MovePlatform function

	RotatePlatform(DeltaTime); // Calls the RotatePlatform function
}

