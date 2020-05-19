// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "SurvivalCharacter.h"

// Sets default values
ASurvivalCharacter::ASurvivalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    cameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    cameraComponent->SetupAttachment(GetMesh());
    cameraComponent->bUsePawnControlRotation = true;
    
    HelmetMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HelmetMesh");
    HelmetMesh->SetupAttachment(GetMesh());
    
    ChestMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ChestMesh");
    ChestMesh->SetupAttachment(GetMesh());
    
    LegsMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LegsMesh");
    LegsMesh->SetupAttachment(GetMesh());
    
    FeetMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FeetMesh");
    FeetMesh->SetupAttachment(GetMesh());
    
    VestMesh = CreateDefaultSubobject<USkeletalMeshComponent>("VestMesh");
    VestMesh->SetupAttachment(GetMesh());
    
    HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandsMesh");
    HandsMesh->SetupAttachment(GetMesh());
    
    BackpackMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BackpackMesh");
    BackpackMesh->SetupAttachment(GetMesh());

}

void ASurvivalCharacter::MoveForward(float val)
{
    if (val != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), val);
    }
}

void ASurvivalCharacter::MoveRight(float val)
{
    if(val != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), val);
    }
    
}

void ASurvivalCharacter::LookUp(float val)
{
    if(val != 0.0f)
    {
        AddControllerPitchInput(val);
    }
}

void ASurvivalCharacter::Turn(float val)
{
    if(val != 0.0f)
    {
        AddControllerYawInput(val);
    }
}

// Called when the game starts or when spawned
void ASurvivalCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASurvivalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent-> BindAxis("MoveForward", this, &ASurvivalCharacter::MoveForward);
    PlayerInputComponent-> BindAxis("MoveRight", this, &ASurvivalCharacter::MoveRight);
    PlayerInputComponent-> BindAxis("LookUp", this, &ASurvivalCharacter::LookUp);
    PlayerInputComponent-> BindAxis("Turn", this, &ASurvivalCharacter::Turn);
}



