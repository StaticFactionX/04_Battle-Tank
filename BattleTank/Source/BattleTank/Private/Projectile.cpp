// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"



// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovementComponent->bAutoActivate = false; 
	// What this does is: It will NOT just fly off until we Fire the Tank. it doesnt bAutoActivate. When we construct, dont send it flying.
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed)
{	
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * Speed); // Equals Launch Velocity  UnitVector * Speed = Velocity? 
	ProjectileMovementComponent->Activate(); // When we Launch Activate so it actually Fires.
}