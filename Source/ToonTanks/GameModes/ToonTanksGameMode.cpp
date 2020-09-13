// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

void AToonTanksGameMode::BeginPlay() 
{
    // Get references and game win/lose conditions.

    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor) 
{
    // Check what type of Actor died. If turret, tally. If player -> go to lose condition.
}

void AToonTanksGameMode::HandleGameStart() 
{
    // Initialise the start countdown, turret activation, pawn check etc.
    // Call Blueprint version GameStart();    
}

void AToonTanksGameMode::HandleGameOver(bool PlayerWon) 
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool )
    
}

