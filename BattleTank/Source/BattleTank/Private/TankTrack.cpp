// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//TODO Clamp actual throttle value so player cant overdrive.
	// Throttle = FMath::Clamp<float>(Throttle, 0, +1.0);   FIRST ATTEMPT AT CLAMPING DID NOT APPEAR TO WORK.

	auto ForceApplied = (GetForwardVector() * Throttle * Max_Track_Driving_Force);
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
	
	
	
	/*   GetOwner goes up the CLASS HIERARCHY to the Owner (Tank_BP [Based on What Ben Said In Video]), Then Down to the RootComponent (Tank) Then, 
 We use Cast HERE because doing TankRoot->AddForce Doesnt work so we need to find the most basic Type of Object we can use to AddForceAtLocation();   */
}



//TODO Tweak Physics Settings.