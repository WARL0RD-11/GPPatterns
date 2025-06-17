// Fill out your copyright notice in the Description page of Project Settings.

#include "GPPatterns/Characters/MyCharacter.h"
#include "MoveRightCommand.h"

void MoveRightCommand::Execute(AMyCharacter* Character, float ActionVal)
{
	if (Character && ActionVal != 0.f)
	{
		Character->AddMovementInput(Character->GetActorRightVector(), ActionVal);
	}
}
