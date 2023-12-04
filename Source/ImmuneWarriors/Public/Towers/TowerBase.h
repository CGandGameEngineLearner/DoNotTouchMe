// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerBase.generated.h"

UCLASS()
class IMMUNEWARRIORS_API ATowerBase : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATowerBase();
	UFUNCTION(BlueprintCallable, Category = "attackTower")
		void attackTower(float attack_value);
	UFUNCTION(BlueprintCallable, Category = "getFirstEnemy")
		ACharacter* getFirstEnemy();
	UFUNCTION(BlueprintCallable, Category = "addEnemy")
		void addEnemy(ACharacter* enemy);
	UFUNCTION(BlueprintCallable, Category = "setAttackVolume")
		void setAttackVolume(float _attack_volume);
	UFUNCTION(BlueprintCallable, Category = "addLevel")
		void addLevel(float _delta_level);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TowerRoperty, meta = (AllowPrivateAccess = "true"))
		float Tower_blood_volume_ = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TowerRoperty, meta = (AllowPrivateAccess = "true"))
		float current_attack_volume_ = 10;
public:
	
		static float attack_volume_s;
		static float max_blood_s;
		static float level_s;
private:
	TQueue<ACharacter*> enemy_queue_;
	size_t enemy_queue_size_ = 0;
};
