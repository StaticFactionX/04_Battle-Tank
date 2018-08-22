// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is MAX Downward Speed, and +1 is MAX Upward Movement.
	void ElevateBarrel(float RelativeSpeed);
	



private:

	UPROPERTY(EditAnywhere, Category = Barrel_Setup)
	float Max_Degrees_Per_Second = 20;  



	UPROPERTY(EditAnywhere, Category = Barrel_Setup)
		float Max_Elevation = 40;
	
	UPROPERTY(EditAnywhere, Category = Barrel_Setup)
		float Min_Elevation = 0;

};