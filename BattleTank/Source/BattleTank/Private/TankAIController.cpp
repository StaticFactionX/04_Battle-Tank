// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();


	auto ControlledTank = GetAIControlledTank();
	{
		if (!ControlledTank)
		{ 
			UE_LOG(LogTemp, Warning, TEXT(" AIController Not Possessing Tank: %s "), *GetPawn()->GetName());
		}
		else 
		{ 
			UE_LOG(LogTemp, Warning, TEXT(" AIController Is Possessing Tank %s "), *GetAIControlledTank()->GetName()); 
		}
	}
};

ATank* ATankAIController::GetAIControlledTank() const
{
	return (Cast<ATank>(GetPawn()));
}