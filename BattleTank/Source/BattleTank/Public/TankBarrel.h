// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
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

	UPROPERTY(EditDefaultsOnly, Category = Barrel_Setup)
	float Max_Degrees_Per_Second = 10;  



	UPROPERTY(EditDefaultsOnly, Category = Barrel_Setup)
		float Max_Elevation = 40;
	//I Think I Want this to remain EditAnywhere that way I can make some tanks harder than others for added challenge, (I May need to adjust fire time)
	
	UPROPERTY(EditDefaultsOnly, Category = Barrel_Setup)
		float Min_Elevation = 0;
	//I Think I Want this to remain EditAnywhere that way I can make some tanks harder than others for added challenge, (I May need to adjust fire time)
};
