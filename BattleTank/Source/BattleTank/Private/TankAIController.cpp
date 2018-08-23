// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	// Super::   Makes Sure the BeginPlay()  on the Super:: Class, is being called
	Super::BeginPlay();


	
	
};



void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); //PlayerTank = Our Pawn Being Cast to a Tank
	auto ControlledTank = (Cast<ATank>(GetPawn())); // Does this Cast the CLASS onto the pawn so i can access its methods with the '->'?
	 
	
	FVector OutHitLocation;

	if (PlayerTank)
	{
		//TODO Move towards Player	
		
		//AimAt Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire At Player
		ControlledTank->Fire(); // TODO Limit Fire Rate
	}
}



