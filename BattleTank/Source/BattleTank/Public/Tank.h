// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward Declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;



UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, Category = Setup) // This Creates a reference that BluePrint can call, called 'SetBarrelReference'
		void SetBarrelReference(UTankBarrel* BarrelToSet); // Declaration


	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	// Sets default values for this pawn's properties
	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();






protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr; 
	// Lecture 137 OR 138  if a refresher is needed,  
	//I Believe this is an instantiation of my class UTankAimingComponent and im giving it the Variable TankAimingComponent, RESEARCH




private:
	
	ATank(); // Constructor

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	


	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 60000;

	
};
