// Copyright 2020 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGeneratedWorldGeneratorsIncludes.h"
#include "VG_FoolsUtopia.generated.h"

UCLASS(Blueprintable)
class UVG_FoolsUtopia : public UVoxelGraphGeneratorHelper
{
	GENERATED_BODY()
	
public:
	// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="", meta=(DisplayName="Layer 0"))
	TSoftObjectPtr<UMaterialInterface> Layer_0 = TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath("/Game/VoxelWorld/VoxelMaterials/MI_QuixelStone.MI_QuixelStone"));
	// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="", meta=(DisplayName="Layer 1"))
	TSoftObjectPtr<UMaterialInterface> Layer_1 = TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath("/Game/VoxelWorld/VoxelMaterials/MI_QuixelDirt.MI_QuixelDirt"));
	// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="", meta=(DisplayName="Layer 2"))
	TSoftObjectPtr<UMaterialInterface> Layer_2 = TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath("/Game/VoxelWorld/VoxelMaterials/MI_QuixelGrass.MI_QuixelGrass"));
	
	UVG_FoolsUtopia();
	virtual TVoxelSharedRef<FVoxelTransformableGeneratorInstance> GetTransformableInstance() override;
};
