// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void RotateBarrel(float RelativeSpeed);

private:
	
	UPROPERTY(EditAnywhere, Category = Barrel_Rotation)
		float Rotation_Max_Degrees_Per_Second = 25;
	//I Think I Want this to remain EditAnywhere that way I can make some tanks harder than others for added challenge, (I May need to adjust fire time)

	
};
