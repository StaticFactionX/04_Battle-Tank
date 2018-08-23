// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 Anything that's within the game (actors, pawns, actor components, etc.) is going to be dynamically allocated and thus be a POINTER. 
 Things like FVector, FRotator, FString etc. aren't
 */



class ATank;


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()


public:


protected:


private: 


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

		
};
