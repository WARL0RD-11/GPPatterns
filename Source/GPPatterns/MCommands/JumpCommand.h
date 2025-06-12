// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ICommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class JumpCommand : public ICommand
{
public:
    virtual void Execute(class AMyCharacter* Character) override;
};
