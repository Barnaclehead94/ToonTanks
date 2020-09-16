// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
<<<<<<< HEAD




}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
=======
}

void APawnBase::RotateTurretFunction(FVector LookAtTarget) 
{
	// Update TurretMesh rotation to face towards the LookAtTarget passed in from Child Classes
	// TurretMesh->SetWorldRotation()...

	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

<<<<<<< HEAD
void APawnBase::Fire() 
{
	// Get ProjectlileSpawnPoint Location && Rotation-> Spawn Projectile Class at location firing towards rotation
	UE_LOG(LogTemp, Warning, TEXT("Fire condition success"));
}
=======
>>>>>>> 4124d3895b6ec9b59a4a067e6c03623631136ff0
>>>>>>> 8ae67b65d6598da5c781f2e281a9fbc72c46b8a8

void APawnBase::HandleDestruction() 
{
	// -- Universal functionality --
	// Play death effects particle, sound and camera shake

	// -- Then do child overrides --
	// -- PawnTurret - Inform GameMode Turred died-> Then Destroy() self.

	// -- PawnTank - Inform GameMode Player died-> Then Hide() all components && stop movement input
}
