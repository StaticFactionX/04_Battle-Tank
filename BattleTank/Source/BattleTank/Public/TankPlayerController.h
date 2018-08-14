// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // MUST be the LAST to be INCLUDED

/**
 * 
 */


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:


private:
	ATank* GetControlledTank() const;

	/*   OVERRIDE:
	 What this says is: "Please make Sure their is something else UP the Inheritance Tree with with Exactly this signature; 'BeginPlay()',                          I.E. NOT BeginPlay(int When) But PRECISELY 'BeginPlay()' WITH NO PARAMETERS!   override checks to see if it can find it up in the Hierarchy  it wil litterally check the tree until it gets to AActor and it finds BeginPlay()   and the Signature/Syntax for BeginPlay()  is virtual void BeginPlay() "
	
	    VIRTUAL VOID:
	
	 When BeginPlay() was first declared up at 'AActor' they use the KEYWORD:  "virtual". and this means: my CHILDREN are ALLOWED to OVERRIDE or EXTEND FUNCTIONAILITY of this METHOD. thats what "virtual does".

	  'virtual' says: If we make a child of this PlayerControllerClass then its children can override and extend the behavior of the Tick method.
	 'override' says: it makes the compiler check to make sure their is a signature pf (Tick(float DeltaTime)) somewhere up the hierarchy tree.
	*/
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override; 


	// Start The tank moving the Barrell So it can Aim and shoot where the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0; // In Centimeters
};