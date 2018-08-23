// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No Need to protect Pointers as added at construction, 
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

	

}




void ATank::Fire()
{
	bool IsReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);

	if (Barrel && IsReloaded)
	{	
		// Spawn a projectile at the socket location.
		auto Projectile = GetWorld()->SpawnActor<AProjectile> // The Variable Projectile can acces members from the class AProjectile.
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // (This is boiler plate code) THIS calls the default behavior before we do ANYTHING ELSE
	
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void ATank::AimAt(FVector OutHitLocation) 
{

	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}



void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet; // Why did we do this? Lecture 154 or 155, i think 155.
}



void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}