// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Called when the game starts or when spawned

APawnTank::APawnTank() // implements the declared constructor
{
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmComp->SetupAttachment(RootComponent); // does not follow base turret / mesh movement, linked to root 

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComp->SetupAttachment(SpringArmComp);
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();

    PlayerControllerRef = Cast<APlayerController>(GetController());

}

void APawnTank::HandleDestruction() 
{
    Super::HandleDestruction();
    // Hide Player. TODO - Create new function to handle this.
    bIsPlayerAlive = false;

    SetActorHiddenInGame(true);
    SetActorTickEnabled(false); // both of these save performance - hides actor and stops update() function running every second
}

bool APawnTank::GetIsPlayerAlive() 
{
    return bIsPlayerAlive;
}


// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Rotate();
    Move();

    if(PlayerControllerRef)
    {
        FHitResult TraceHitResult;
        PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
        FVector HitLocation = TraceHitResult.ImpactPoint;

        RotateTurretFunction(HitLocation);
    }
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
    PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput); // fully bound to movement input
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}

void APawnTank::CalculateMoveInput(float Value) 
{
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float Value) 
{
    float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    FRotator Rotation = FRotator(0, RotateAmount, 0);
    RotationDirection = FQuat(Rotation);
}

void APawnTank::Move() 
{
    AddActorLocalOffset(MoveDirection, true); // sweep option, check if collisions should be checked when actor is moving
}

void APawnTank::Rotate() 
{
    AddActorLocalRotation(RotationDirection, true);
}
