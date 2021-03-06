// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"



// Forward Delcaration, Allows us to use UTankBarrel Class
class UTankBarrel;
class UTankTurret;



// Holds Barrels Poperties. and Elevate Method.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	


	// Sets default values for this component's properties
	UTankAimingComponent();  // CONSTRUCTOR.

	void AimAt(FVector OutHitLocation, float LaunchSpeed);



	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	


protected:
	

private:
	
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
