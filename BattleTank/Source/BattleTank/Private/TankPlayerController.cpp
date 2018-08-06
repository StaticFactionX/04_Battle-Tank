// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


/*
INHERITANCE HIERARCHY:
'UObjectBase'  <---  'UObjectBaseUtility'  <---  'UObject'  <---  'AActor'  <---  'AController'  <---  'APlayerController'  <---  'ADebugCameraController'.

SIDE NOTE:  "AActor is the last Class with BeginPlay()".
*/
void ATankPlayerController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();

	
	auto ControlledTank = GetControlledTank();

if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT(" PlayerController Not Possessing Tank: %s "), *GetPawn()->GetName()); }
else { UE_LOG(LogTemp, Warning, TEXT(" PlayerController Is Possessing The Tank: %s "), *GetControlledTank()->GetName()); }

};

//TICK
void ATankPlayerController::Tick(float DeltaTime)
{	//super
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

	
ATank* ATankPlayerController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn());
	}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; } // If their is NO controlled Tank, we need to GTFO.

	FVector OutHitLocation; //Out Parameter

		if (GetSightRayHitLocation(OutHitLocation)) // Has a "Side-Effect, is going to Ray-Trace."
	{
		UE_LOG(LogTemp, Warning, TEXT("OutHitLocation: %s"), *OutHitLocation.ToString());
	}
	
	
	//if it hits the landscape, return true
		//we want the controlled tank to aim to this point.
}

// Get world location if linetrace through crosshair, true if it hits the landscape
// make sure to access Class. and pass a reference to FVector, change to "OutHitLocation"
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{
	OutHitLocation = FVector(1.0);
	return true;
}