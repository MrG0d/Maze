// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayHUD.h"
#include "MazeClean.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "MainCharacter.h"
#include "MazeCleanGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

APlayHUD::APlayHUD() {
	static ConstructorHelpers::FObjectFinder<UFont> HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}
//APlayHUD::APlayHUD(const class FPostContstructInitializeProperties &PCIP){
//	static ConstructorHelpers::FObjectFinder<UFont> HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
//	HUDFont = HUDFontOb.Object;
//}

void APlayHUD::DrawHUD()
{
	// Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	// Call to the parent versions of DrawHUD
	Super::DrawHUD();

	// Get the character and print its power level.
	AMainCharacter * Character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	FString PowerLevelString = FString::Printf(TEXT("%10.1f"), FMath::Abs(Character->GetSpeed()));
	DrawText(PowerLevelString, FColor::Black, 50, 50, HUDFont);

	//AMazeCleanGameModeBase* GameMode = Cast<AMazeCleanGameModeBase>(UGameplayStatics::GetGameMode(this));

	// If the game is over.
	//if (GameMode->GetCurrentState() == ETutorialCodePlayState::EGameOver)
	//{
	//	// Create a variable for storing the size of printing Game Over.
	//	FVector2D GameOverSize;
	//	GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
	//	DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDimensions.X - GameOverSize.X) / 2.f, (ScreenDimensions.Y - GameOverSize.Y) / 2.f, HUDFont);
	//}
}




