// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpCommand.h"
#include "GPPatterns/Characters/MyCharacter.h"

void JumpCommand::Execute(AMyCharacter* Character)
{
	if (Character)
	{
		Character->Jump();
	}
}
