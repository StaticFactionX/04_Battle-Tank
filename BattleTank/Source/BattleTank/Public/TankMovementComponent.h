// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()




public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	//TODO: Fix why it won't show input direction, I belive it's because it's a keyboard giving the Input.
	//TODO: Try Input setup with a GamePad.
	//TODO: See if my functions are ACTUALLY being called!



protected:




private:

	
	
};
