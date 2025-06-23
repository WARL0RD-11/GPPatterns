// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftCommand.h"
#include "GPPatterns/Characters/MyCharacter.h"

void MoveLeftCommand::Execute(AMyCharacter* Character, float ActionVal)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("Left"))
		);
	}

	if (Character && ActionVal != 0.f)
	{
		Character->AddMovementInput(Character->GetActorRightVector(), ActionVal);
	}
}
