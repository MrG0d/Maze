// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MazeCleanGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MAZECLEAN_API AMazeCleanGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	AMazeCleanGameModeBase(const FObjectInitializer& ObjectInitializer);
	virtual void StartPlay() override;
	
};
