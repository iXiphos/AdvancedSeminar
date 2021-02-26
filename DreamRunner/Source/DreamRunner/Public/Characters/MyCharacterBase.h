// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "MyCharacterBase.generated.h"

UCLASS()
class DREAMRUNNER_API AMyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void HoriMove(float value);
	void VertMove(float value);

	UFUNCTION(BlueprintCallable, Category = "MyCharacterBase functions")
		static void DeathFromSpikes(AActor* actor);

	void CheckJump();

	UPROPERTY()
		bool jumping;
};
