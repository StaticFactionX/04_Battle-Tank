// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrellReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet; // We have delegated the BarrelToSet to the "UTankAimingComponent"
}




// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
	
	// Returns a bool
	if (UGameplayStatics::SuggestProjectileVelocity 
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

	)
		)    // Calculate The OutLaunchVelocity, then:
	
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // GetSafeNormal() turns it into a Unit Vector.
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT(" %s Firing At:  %s "), *TankName, *AimDirection.ToString());
		// You Only use a  '*'  if you're trying to get an FString out of the Variable, in this case the FString is our name.

	}
}

