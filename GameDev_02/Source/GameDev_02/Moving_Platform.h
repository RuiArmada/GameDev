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

	UPROPERTY(EditAnywhere) // Tells UE that this variable needs to appear in blueprints
	FVector MyVector = FVector(5,2,5);

	UPROPERTY(EditAnywhere) // Tells UE that this variable needs to appear in blueprints
	float MyX;

};
