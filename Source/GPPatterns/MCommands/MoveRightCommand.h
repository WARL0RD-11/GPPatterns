// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ICommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class GPPATTERNS_API MoveRightCommand : public ICommand
{
public:
	virtual void Execute(AMyCharacter* Character, float ActionVal) override;
};
