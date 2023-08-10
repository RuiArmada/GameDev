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

	MyVector.Y = MyVector.Y + 1; // Actor will move 1 unit up every frame

	SetActorLocation(MyVector);

}

