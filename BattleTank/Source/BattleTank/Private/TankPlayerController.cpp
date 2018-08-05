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
	
ATank* ATankPlayerController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn());
	}



