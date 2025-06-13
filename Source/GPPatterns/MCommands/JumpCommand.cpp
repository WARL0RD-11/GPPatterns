// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpCommand.h"
#include "GPPatterns/Characters/MyCharacter.h"

void JumpCommand::Execute(AMyCharacter* Character)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Yellow,
			FString::Printf(TEXT("SUII"))
		);
	}
	if (Character)
	{
		Character->Jump();
	}
}
