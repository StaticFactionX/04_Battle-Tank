// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, +1.f);

	auto ElevationChange = RelativeSpeed * Max_Degrees_Per_Second * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation =  FMath::Clamp<float>(RawNewElevation, Min_Elevation, Max_Elevation);
	
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}

