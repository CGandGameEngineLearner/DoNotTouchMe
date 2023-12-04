// Fill out your copyright notice in the Description page of Project Settings.



#include "Warriors/WarriorBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

// Sets default values
AWarriorBase::AWarriorBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AWarriorBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWarriorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



void AWarriorBase::moveForward(float value)
{
	AddMovementInput(FVector(1, 0, 0), value);
}
void AWarriorBase::moveRight(float value)
{
	AddMovementInput(FVector(0, 1, 0), value);
}

void AWarriorBase::WarriorBaseJump()
{
	Jump();
}

void AWarriorBase::startSprint()
{
	if(!b_is_slowing_down_)
	{
		GetCharacterMovement()->MaxWalkSpeed = sprint_speed;
	}
}
void AWarriorBase::endSprint()
{
	if(!b_is_slowing_down_)
	{
		GetCharacterMovement()->MaxWalkSpeed = walk_speed;
	}
}

void AWarriorBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AWarriorBase::reducedBlood(float reduced_blood_volumn)
{
	blood_volume_ -= reduced_blood_volumn;
}

void AWarriorBase::slowDown(float new_slow_speed)
{
	b_is_slowing_down_=true;
	GetCharacterMovement()->MaxWalkSpeed =new_slow_speed;
	
}

void AWarriorBase::returnToNormalSpeed()
{
	b_is_slowing_down_=false;
	GetCharacterMovement()->MaxWalkSpeed = walk_speed;
}
