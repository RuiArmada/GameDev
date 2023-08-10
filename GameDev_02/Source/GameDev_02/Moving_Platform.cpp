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
			- Reverese direction of motion
	
	*/

	// ## 1. ##

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation.X = CurrentLocation.X + 1;

	SetActorLocation(CurrentLocation);

}

