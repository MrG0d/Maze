// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAZECLEAN_API APlayHUD : public AHUD
{
	GENERATED_BODY()
public:
	APlayHUD();
	//APlayHUD(const class FPostContstructInitializeProperties &PCIP);

	UPROPERTY()
	UFont *HUDFont;
	virtual void DrawHUD() override;
	
};
