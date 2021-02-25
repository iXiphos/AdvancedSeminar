// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyCharacterBase.h"

// Sets default values
AMyCharacterBase::AMyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	jumping = false;

}

// Called when the game starts or when spawned
void AMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
	{
		Jump();
	}
	VertMove(1);

}

// Called to bind functionality to input
void AMyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacterBase::HoriMove);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacterBase::CheckJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacterBase::CheckJump);

}

void AMyCharacterBase::HoriMove(float value)
{
	value *= 2;
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AMyCharacterBase::VertMove(float value)
{
	AddMovementInput(GetActorForwardVector(), 2);
}

void AMyCharacterBase::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
}

