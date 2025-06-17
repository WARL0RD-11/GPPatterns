// Fill out your copyright notice in the Description page of Project Settings.

#include "GPPatterns/Characters/MyCharacter.h"
#include "MoveRightCommand.h"

void MoveRightCommand::Execute(AMyCharacter* Character, float ActionVal)
{	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("Right"))
		);
	}

	if (Character && ActionVal != 0.f)
	{
		Character->AddMovementInput(Character->GetActorRightVector(), ActionVal);
	}
}
