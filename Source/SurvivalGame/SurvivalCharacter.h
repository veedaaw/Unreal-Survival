// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SurvivalCharacter.generated.h"

UCLASS()
class SURVIVALGAME_API ASurvivalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASurvivalCharacter();
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class UCameraComponent* cameraComponent;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* HelmetMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* ChestMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* LegsMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* FeetMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* VestMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* HandsMesh;
    
    UPROPERTY(EditAnywhere, Category = "Components")
    class USkeletalMeshComponent* BackpackMesh;
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    void MoveForward(float val);
    void MoveRight(float val);
    void LookUp(float val);
    void Turn(float val);
    

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
