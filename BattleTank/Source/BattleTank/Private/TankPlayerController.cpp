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

	// Get world location if linetrace through crosshair
	//if it hits the landscape,
		//we want the controlled tank to aim to this point.
}
