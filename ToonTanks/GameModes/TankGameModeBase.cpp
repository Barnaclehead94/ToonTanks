// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay() 
{
    // Get references and game win/lost conditions

    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of ACtor has died. If Turret, tally. If Player -> go to lost condition.
    UE_LOG(LogTemp, Warning, TEXT("A Pawn died"));
}
void ATankGameModeBase::HandleGameStart() 
{
    
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    
}


