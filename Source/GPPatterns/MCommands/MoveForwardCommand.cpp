// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveForwardCommand.h"
#include "GPPatterns/Characters/MyCharacter.h"

void MoveForwardCommand::Execute(AMyCharacter* Character, float Value)
{	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("FORWARD"))
		);
	}

	if (Character && Value != 0.f)
	{
		Character->AddMovementInput(Character->GetActorForwardVector(), Value);
	}
}
