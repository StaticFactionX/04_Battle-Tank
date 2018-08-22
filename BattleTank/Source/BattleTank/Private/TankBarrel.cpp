// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	/// Move the Barrel the right amount this frame
//	*Allow for A limited Degree Of Motion, I.E. 360 Degrees, or 180, How Far Up Can it go How Far Down

///Given a Max Elevation Speed and the Frame Time.
//	*returns OutHitLocation but with the added benefit of moving the Barrel.

	UE_LOG(LogTemp, Warning, TEXT(" BarrelElevatee() Called at speed %f "), RelativeSpeed);
}

