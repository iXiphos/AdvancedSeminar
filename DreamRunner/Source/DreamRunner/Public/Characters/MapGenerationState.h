// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MapGenerationState.generated.h"

class PlatformActor;

/**
 * 
 */
UCLASS()
class DREAMRUNNER_API AMapGenerationState : public AGameStateBase
{
	GENERATED_BODY()


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:



};
