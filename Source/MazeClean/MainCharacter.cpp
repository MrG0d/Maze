// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AMainCharacter::AMainCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	CameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetMesh());
	 //Position the camera a bit above the eyes
	CameraComponent->RelativeLocation = FVector(-90, 0, 80);
	 //Allow the pawn to control rotation.
	CameraComponent->bUsePawnControlRotation = true;

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("AMainCharacter create"));
	}
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using AMainCharacter!"));
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::OnStopJump);
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("SetupPlayerInputComponent"));
	}
}

void AMainCharacter::MoveForward(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Controller is NULL"));
	//UE_LOG(LogTemp, Warning, TEXT("Value is %f"), Value);
	
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("FORWARD"));
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}


void AMainCharacter::OnStartJump()
{
	bPressedJump = true;
}

void AMainCharacter::OnStopJump()
{
	bPressedJump = false;
}