// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true); // tells world timer manager to create new timer to manage, updates every (FireRate) seconds

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0)); // casting - convert type to another, declares PlayerPawn as a pawn & gets player info. This reference variable can now be used to reference the player anywhere

}

void APawnTurret::HandleDestruction() 
{
    // Call base pawn class HandleDestruction to play effects
    Super::HandleDestruction();
    Destroy();
    
}


// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition() // ensures this is binded to check fire condition
{
    // If Player == null || is Dead THEN BAIL!!
    if(!PlayerPawn)
    {
        return;
    }
    //If Player IS in range THEN FIRE!!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }

}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn)
    {
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
