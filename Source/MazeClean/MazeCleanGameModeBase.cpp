// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCleanGameModeBase.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "MainCharacter.h"

AMazeCleanGameModeBase::AMazeCleanGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Blueprint/BP_MainCharacter.BP_MainCharacter_C'"));
	//if (PlayerPawnObject.Class != NULL)
	if (true)
	{
		//DefaultPawnClass = PlayerPawnObject.Class;
		DefaultPawnClass = AMainCharacter::StaticClass();
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("PlayerPawnObject create"));
		}
	} else {
		if (GEngine){
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("PlayerPawnObject is NULL"));
		}
		//UE_LOG(LogTemp, Warning, TEXT("PlayerPawnObject is NULL"));
	}
}

// Note that engine version 4.3 changed the method's name to StartPlay(), because of this engine versions before 4.3, or older tutorials, use BeginPlay()
void AMazeCleanGameModeBase::StartPlay()
{
	Super::StartPlay();
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("AMazeCleanGameModeBase::StartPlay()"));
	}
}