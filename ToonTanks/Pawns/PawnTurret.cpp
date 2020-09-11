// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true); // tells world timer manager to create new timer to manage, updates every (FireRate) seconds
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void APawnTurret::CheckFireCondition() // ensures this is binded to check fire condition
{
    // If Player == null || is Dead THEN BAIL!!

    //If Player IS in range THEN FIRE!!

    UE_LOG(LogTemp, Warning, TEXT("Fire condition checked"));
}
