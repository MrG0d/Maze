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
	UE_LOG(LogTemp, Warning, TEXT("HUD create"));
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
	if (Character != NULL) {
		FString Speed = FString::Printf(TEXT("Speed: %10.1f"), FMath::Abs(Character->GetSpeed()));
		DrawText(Speed, FColor::Black, 10, 50, HUDFont);


		//FString Direction = FString::Printf(TEXT("Direction: %10.1f"), FMath::Abs(Character->GetDirection()));
		//DrawText(Direction, FColor::Black, 10, 75, HUDFont);
	}

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




