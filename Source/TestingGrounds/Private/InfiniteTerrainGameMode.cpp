// Curiouser Games

#include "InfiniteTerrainGameMode.h"
#include "GameFramework/Volume.h"
#include "EngineUtils.h"


void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<AVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddToPool(AVolume * VolumeToAdd)
{
	auto VolumeName = VolumeToAdd->GetName();
	if(VolumeName.Contains(FString("NavMesh"),ESearchCase::CaseSensitive,ESearchDir::FromStart))
	UE_LOG(LogTemp, Warning, TEXT("Found NavMesh %s"), *VolumeToAdd->GetName());
}
