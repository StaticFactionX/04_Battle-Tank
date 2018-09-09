// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward Declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;
class UTankMovementComponent;




UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// This Creates a reference that BluePrint can call, called 'SetBarrelReference'
	UFUNCTION(BlueprintCallable, Category = Setup) 
	void SetBarrelReference(UTankBarrel* BarrelToSet); // Declaration

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	// Sets default values for this pawn's properties
	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();



protected:
	// Lecture 137 OR 138  if a refresher is needed,  
	//I Believe this is an instantiation of my class UTankAimingComponent and im giving it the Variable TankAimingComponent, RESEARCH

	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr; //TODO potentially Remove/Add This Nullptr
	
	// TODO, figure out (nullptr in Great detail) ---> Is this just Somewhere to store the Pointer?




private:
	
	ATank(); // Constructor

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called to bind functionality to input
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 60000;
	//TODO: Fix Tank Aiming Distance, WITHOUT changing how fast the Prjoectile Shoots, I Believe their is an Equation around here somewhere.

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3.0;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local Barrel Reference for spawning projectile.
	UTankBarrel* Barrel = nullptr;


	

	double LastFireTime = 0;
	
};
