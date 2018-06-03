// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "MainCharacter.generated.h"


UCLASS()
class MAZECLEAN_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UCameraComponent* CameraComponent;


private:
	 //handles moving forward/backward
    UFUNCTION()
		void MoveForward(float Val);
    //handles strafing
    UFUNCTION()
		void MoveRight(float Val);
	//sets jump flag when key is pressed
	UFUNCTION()
		void OnStartJump();
	//clears jump flag when key is released
	UFUNCTION()
		void OnStopJump();
};
