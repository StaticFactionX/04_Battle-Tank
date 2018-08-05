// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();


	auto PlayerTank = GetPlayerTank();
	{
		if (!PlayerTank)
		{ 
			UE_LOG(LogTemp, Warning, TEXT(" AIController Can't find Player Tank "));
		}
		else 
		{ 

			UE_LOG(LogTemp, Warning, TEXT(" AIController Found Player: %s "), *PlayerTank->GetName()); 
		}
	}
};

ATank* ATankAIController::GetControlledTank() const
{
	return (Cast<ATank>(GetPawn()));
}


ATank* ATankAIController::GetPlayerTank() const // does this method EXPECT A POINTER coming back to ATank* ?
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);  // Returns a cast to a TYPE <ATank>, and we cast it onto PlayerPawn
}