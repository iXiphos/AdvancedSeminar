// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyMapGeneration.h"
#include "PlatformActor.h"


void AMyMapGeneration::BeginPlay()
{
	Super::BeginPlay();
	GenerateMap(10);
}

void AMyMapGeneration::GenerateMap(int spawnedTilesLength)
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	int size = tiles.Num();

	for (int i = 0; i < spawnedTilesLength; i++)
	{
		int randomTile = FMath::RandRange(0, size);
		FActorSpawnParameters SpawnInfo;
		AActor* tileSpawn = &tiles[randomTile];

		UObject* ClassPackage = ANY_PACKAGE;
		UObject* ObjectToSpawn = FindObject<UObject>(ClassPackage, TEXT("\Content\ThirdPersonBP\Blueprints\FloorBP.uasset"));
		UClass* ClassToSpawn = ObjectToSpawn->StaticClass();
		//Do Collision Checks with SpawnInfo
		GetWorld()->SpawnActor<PlatformActor>(BlueprintVar[i].Get(), Location, Rotation, SpawnInfo);
		Location = BlueprintVar[i].getNextSpawnPoint();
	}
}

void AMyMapGeneration::LoadNextTile(FVector spawnLocation)
{
	FVector spawnLoc(tiles[tiles.Num()].GetActorLocation());
	UObject* ClassPackage = ANY_PACKAGE;
	
	UObject* ObjectToSpawn = FindObject<UObject>(ClassPackage, TEXT("\Content\ThirdPersonBP\Blueprints\FloorBP.uasset"));
	UClass* ClassToSpawn = ObjectToSpawn->StaticClass();
	ASpawnedTiles.Pop(true);

	//Random Spawn then add to stack

}