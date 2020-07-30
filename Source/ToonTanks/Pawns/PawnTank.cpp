// Fill out your copyright notice in the Description page of Project Settings.
#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawnTank::APawnTank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sprint arm"));
    SpringArm->SetupAttachment(RootComponent);
    
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Move();
    Rotate();
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalulateMoveInput);
    PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalulateRotateInput);
}

void APawnTank::CalulateMoveInput(float Value) 
{
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalulateRotateInput(float Value) 
{
    float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
    FRotator Rotation = FRotator(0, RotateAmount, 0);
    RotationDirection = FQuat(Rotation);
}

void APawnTank::Move() 
{
    AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate() 
{
    AddActorLocalRotation(RotationDirection, true);
}
