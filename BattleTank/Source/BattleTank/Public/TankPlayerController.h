// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "CoreMinimal.h"
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
	ATank* GetControlledTank() const;

	/*   OVERRIDE:
	 What this says is: "Please make Sure their is something else UP the Inheritance Tree with with Exactly this signature; 'BeginPlay()',                          I.E. NOT BeginPlay(int When) But PRECISELY 'BeginPlay()' WITH NO PARAMETERS!   override checks to see if it can find it up in the Hierarchy  it wil litterally check the tree until it gets to AActor and it finds BeginPlay()   and the Signature/Syntax for BeginPlay()  is virtual void BeginPlay() "
	
	    VIRTUAL VOID:
	
	 When BeginPlay() was first declared up at 'AActor' they use the KEYWORD:  "virtual". and this means: my CHILDREN are ALLOWED to OVERRIDE or EXTEND FUNCTIONAILITY of this METHOD. thats what "virtual does".
	*/
	virtual void BeginPlay() override;
	
};