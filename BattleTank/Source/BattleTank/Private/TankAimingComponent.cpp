// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) {	return; }

	Barrel = BarrelToSet; // We have delegated the BarrelToSet to the "UTankAimingComponent"
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) {	return; }

	Turret = TurretToSet;
}



void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
	/*
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	DELETED on Bens Comp COmmented out on mine so i remember what i did.
	*/

	if (!Barrel) { return; }

		FVector OutLaunchVelocity;   // Initialized to  Zero(0).
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // If String isnt found it returns to the "Barrel". fails nicely. 
	

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity 
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		); 
	
	// Calculate The OutLaunchVelocity, then:
		if (bHaveAimSolution)
		{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // GetSafeNormal() turns it into a Unit Vector.
		MoveBarrelTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" %f: AimSolution Found. "), Time);

		}

			else

			{
				auto Time = GetWorld()->GetTimeSeconds();
				UE_LOG(LogTemp, Warning, TEXT(" %f: No AimSolution Found. "), Time);
			}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	///Bens
	//*Mine 
	
		/// Work-out current difference between Barrel Rotation, and Aim Direction
		//	*Assign Our Input (I.E. our Mouse/Gamepad Movement to the CrossHair, and make the Barrell Follow The CrossHair/Input

	auto BarrelRotator = Barrel->GetForwardVector().Rotation(); // Gets the Rotation at this moment it's pretty Static, no need to log out. Lec 142
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	

	Barrel->ElevateBarrel(DeltaRotator.Pitch); 
	// SIDE NOTE: The Number in the () is the Relative Speeds Input that gets passed to Relative Speed the Variable and that's how the calculations work.
}


