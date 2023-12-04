// Fill out your copyright notice in the Description page of Project Settings.


#include "Towers/TowerBase.h"

float ATowerBase::level_s = 1;
float ATowerBase::max_blood_s = 100;
float ATowerBase::attack_volume_s = 10;
// Sets default values
ATowerBase::ATowerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void  ATowerBase::attackTower(float attack_value)
{
	Tower_blood_volume_ -= attack_value;
}
void ATowerBase::addEnemy(ACharacter* enemy)
{
	if (enemy_queue_size_ < 5)
	{
		enemy_queue_.Enqueue(enemy);
		enemy_queue_size_++;
	}
	
}
void ATowerBase::addLevel(float _delta_level)
{
	level_s += _delta_level;
	max_blood_s *= level_s;
	attack_volume_s*= level_s;
	Tower_blood_volume_ = max_blood_s;
	current_attack_volume_ = attack_volume_s;
}
void ATowerBase::setAttackVolume(float _attack_volume)
{
	attack_volume_s = _attack_volume;
}
ACharacter* ATowerBase::getFirstEnemy()
{
	ACharacter* FirstEnemy;
	if (enemy_queue_.Dequeue(FirstEnemy))
	{
		return FirstEnemy;
	}

	return nullptr;
}

