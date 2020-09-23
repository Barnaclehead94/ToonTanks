// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController // interface directly receiving input notifications when something is pressed + to enable and disable player input
{
	GENERATED_BODY()

public:

	void SetPlayerEnableState(bool SetPlayerEnabled);
};
