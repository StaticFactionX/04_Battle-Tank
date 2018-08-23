// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"




void UTankTurret::RotateBarrel(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, +1.f);
	
	auto RotationChange = RelativeSpeed * Rotation_Max_Degrees_Per_Second * GetWorld()->DeltaTimeSeconds;

	auto Rotation = RelativeRotation.Yaw + RotationChange; 
	
	SetRelativeRotation(FRotator(0, Rotation, 0));

}