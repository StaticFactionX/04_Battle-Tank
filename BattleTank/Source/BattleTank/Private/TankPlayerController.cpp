// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"




/*
INHERITANCE HIERARCHY:

'UObjectBase'  <---  'UObjectBaseUtility'  <---  'UObject'  <---  'AActor'  <---  'AController'  <---  'APlayerController'  <---  'ADebugCameraController'.

SIDE NOTE:  "AActor is the last Class with BeginPlay()".
*/
void ATankPlayerController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();
};

//TICK
void ATankPlayerController::Tick(float DeltaTime)
{	//super
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

	
ATank* ATankPlayerController::GetControlledTank() const
	{
		return Cast<ATank>(GetPawn()); // CAST TEMPLATE FUNCTIONS-------- DO RESEARCH!
	}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; } // If their is NO controlled Tank, we need to GTFO.

	FVector OutHitLocation; //Out-Parameter

		if (GetSightRayHitLocation(OutHitLocation)) // Has a "Side-Effect, is going to Ray-Trace."
	{
			GetControlledTank()->AimAt(OutHitLocation);
		
	}
	
	
	//if it hits the landscape, return true
		//we want the controlled tank to aim to this point.
}



/// Get world location if linetrace through crosshair, true if it hits the landscape                                                                          Make sure to access Class. [and pass a reference to FVector&, the reference is OutHitLocation].
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const   
{
	/// STEP 1    Find CrossHair Position  ( We Found The CrossHair postiion In Pixels. )
		int32 ViewportSizeX;
		int32 ViewportSizeY;	
	///QUESTION:  Do the Passed variables get DEFINED once passed, Does GetViewPortSize DEFINE them for me automatically? //
		GetViewportSize(ViewportSizeX, ViewportSizeY); //GetViewPortSize() Built-in Helper Method.

		auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	/*
	EXAMPLE: IF (('ViewportSizeX' = 1000 PX) * (CrossHairXLocation = 0.5)) then the ScreenLocation for X = 500 PX Across, Do The Same Calulation For 'Y'

	UE_LOG(LogTemp, Warning, TEXT(" ScreenLocation: %s"), *ScreenLocation.ToString()); In Case we wanna Make Sure ScreenLocation is working.

	STEP 2:  "De-Project" The Screen-Position of the CrossHair to a WorldDirection.
	*/
	

		FVector LookDirection;
		if (GetLookDirection(ScreenLocation, LookDirection))
		{
			/// STEP 3   Line-Trace along through that direction, and see what we hit with some maximum Range.
			GetLookVectorHitLocation(LookDirection, OutHitLocation);
		}
	return true;
}



bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const /// ! Remember to Add PARAMETERS To DECLARATION. !
{
		FVector CameraWorldLocation; // (TO Be DISCARDED  < - - - -  >  "LookDirection" Comes in as a REFERENCE in our OUT-PARAM)

		return DeprojectScreenPositionToWorld
		(
			ScreenLocation.X,    // float
			ScreenLocation.Y,    // float
			CameraWorldLocation, // FVector &
			LookDirection       // FVector &
		);	
		
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const 
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto  EndLocation = StartLocation + (LookDirection *  LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;

	}
	OutHitLocation = FVector(0);
	return false;
}

/*
QUESTION 1:
8/13/18
IF A FUNCTION 1, CALLS FUNCTION 2 
[I.E.  Function2(){} ] 
AND FUNCTION 1 HAS A VARIABLE OF 'A' CAN FUNCTION 2 HAVE  '&A'  PASSED IN,   OR NOT BECAUSE IT'S TECHNICALLY "OUT OF SCOPE"? Test LATER IN V.S. 

QUESTION 2: Is an Out Parameter just another word for a variable being passed into a function, as in it comes from the OUTSIDE of the function?
*/