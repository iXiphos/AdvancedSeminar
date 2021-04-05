// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformActor.generated.h"

UCLASS()
class DREAMRUNNER_API APlatformActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector nextSpawnPoint;

	FVector getNextSpawnPoint() { return nextSpawnPoint; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
