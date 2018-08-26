// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "TankTrack.generated.h"


/// Anything in the Multi-Line Comment will show up on the Object in Blue-Print if you HOVER your mouse over it, this is a good way to previde details.
 /*  TankTrack is used to set maximum Driving Force, And to apply forces to the tank.   */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// Sets Thottle Between -1, and +1.
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	

	// Max Force Per Track In Newtons. ( N. ) F=ma.
	UPROPERTY(EditDefaultsOnly)
	float Max_Track_Driving_Force = 400000; // Assum Tank is 40 Tons, and we have 1G of Acceleration.

};
