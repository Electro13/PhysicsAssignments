// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsAssignment1.h"

// Sets default values
APhysicsAssignment1::APhysicsAssignment1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));

	//Set the initial velocity
	SphereMovement->InitialSpeed = 300.0f;
	//This will turn off the gravity
	SphereMovement->ProjectileGravityScale = 0;

	angVelocity.Y = 45;
}

// Called when the game starts or when spawned
void APhysicsAssignment1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsAssignment1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FQuat angVel(0, angVelocity.X, angVelocity.Y, angVelocity.Z);
	position += vel * DeltaTime + 0.5 * DeltaTime * DeltaTime;
	vel += acceleration * DeltaTime;
	orientaion += (angVel * orientaion * (DeltaTime / 2));
	orientaion.Normalize();
	angVel = orientaion;
	APhysicsAssignment1::SetActorRotation(orientaion);
}

void APhysicsAssignment1::RotMotion() {

}