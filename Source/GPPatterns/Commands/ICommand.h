// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class AMyCharacter;

class GPPATTERNS_API ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Execute(AMyCharacter* Character) = 0;
};
