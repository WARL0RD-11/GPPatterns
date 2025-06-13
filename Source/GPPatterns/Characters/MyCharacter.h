// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class GPPATTERNS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UCameraComponent> Camera;

};
