// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WarriorBase.generated.h"

UCLASS()
class IMMUNEWARRIORS_API AWarriorBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorBase();
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	UFUNCTION(BlueprintCallable, Category = "moveForward")
		void moveForward(float value);
	UFUNCTION(BlueprintCallable, Category = "moveRight")
		void moveRight(float value);

	UFUNCTION(BlueprintCallable, Category = "jump")
		void WarriorBaseJump();
	
	UFUNCTION(BlueprintCallable, Category = "startSprint")
		void startSprint();
	UFUNCTION(BlueprintCallable, Category = "endSprint")
		void endSprint();
	UFUNCTION(BlueprintCallable, Category = "reducedBlood")
		void reducedBlood(float reduced_blood_volumn);

	UFUNCTION(BlueprintCallable, Category = "slowdown")
		void slowDown(float new_slow_speed);

	UFUNCTION(BlueprintCallable, Category = "slowdown")
		void returnToNormalSpeed();
	
public:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move, meta = (AllowPrivateAccess = "true"))
		bool b_is_slowing_down_=false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move, meta = (AllowPrivateAccess = "true"))
		float sprint_speed = 2200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Move, meta = (AllowPrivateAccess = "true"))
		float walk_speed = 800.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WarriorProperty, meta = (AllowPrivateAccess = "true"))
		float blood_volume_ = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WarriorProperty, meta = (AllowPrivateAccess = "true"))
		float max_blood_volume_ = 100.0f;
};
