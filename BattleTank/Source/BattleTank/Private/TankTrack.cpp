// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s Tracks Throttle is: %f "), *Name, Throttle);


	//TODO Clamp actual throttle value so player cant overdrive.

	auto ForceApplied = GetForwardVector() * Throttle * Max_Track_Driving_Force;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
	/*   GetOwner goes up the CLASS HIERARCHY to the Owner (Tank_BP [Based on What Ben Said In Video]), Then Down to the RootComponent (Tank) Then, 
 We use Cast HERE because doing TankRoot->AddForce Doesnt work so we need to find the most basic Type of Object we can use to AddForceAtLocation();   */
}

