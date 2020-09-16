// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> 4124d3895b6ec9b59a4a067e6c03623631136ff0
>>>>>>> 8ae67b65d6598da5c781f2e281a9fbc72c46b8a8
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))	
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

public:
	// Sets default values for this pawn's properties
	APawnBase();
<<<<<<< HEAD
	// Called every frame
	virtual void Tick(float DeltaTime) override;

<<<<<<< HEAD
protected:

	void RotateTurretFunction(FVector LookAtTarget);

	void Fire();

	virtual void HandleDestruction(); // virutal specifier alerts us to the nature of this method - is expected to be overriden by a child class

=======
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
=======

>>>>>>> 4124d3895b6ec9b59a4a067e6c03623631136ff0
>>>>>>> 8ae67b65d6598da5c781f2e281a9fbc72c46b8a8
};
