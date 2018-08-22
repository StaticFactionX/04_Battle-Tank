// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();


	auto PlayerTank = GetPlayerTank();
	{
		if (!PlayerTank)
		{ 
			UE_LOG(LogTemp, Warning, TEXT(" AI_Controller Can't find the Player Tank "));
		}
		else 
		{ 

			UE_LOG(LogTemp, Warning, TEXT(" AI_Controller Found the Player: %s "), *PlayerTank->GetName()); 
		}
	}
};



void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


	FVector OutHitLocation;

	if (GetPlayerTank())
	{
		//TODO Move towards PLayer

		//AimAt Player.
		// Get The Tank the A.I. is posessing, make it AimAt Player/User.

		

		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT(" Aiming At Player "));
		

		// Fire When Ready
	}




}



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

