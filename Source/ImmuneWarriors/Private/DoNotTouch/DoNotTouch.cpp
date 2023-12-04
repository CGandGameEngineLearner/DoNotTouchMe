// Fill out your copyright notice in the Description page of Project Settings.


#include "DoNotTouch/DoNotTouch.h"

// Sets default values
ADoNotTouch::ADoNotTouch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ADoNotTouch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoNotTouch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

