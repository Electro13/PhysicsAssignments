// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Math/Quat.h"
#include "PhysicsAssignment1.generated.h"

UCLASS()
class PHYSICS_API APhysicsAssignment1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsAssignment1();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* SphereMovement;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RotMotion();

	FVector position;
	FVector rotation;
	FVector acceleration;
	FVector vel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector angVelocity;
	FQuat orientaion;
};
