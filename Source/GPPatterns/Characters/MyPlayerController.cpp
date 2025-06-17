// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MyCharacter.h"

#include "GPPatterns/MCommands/JumpCommand.h"
#include "GPPatterns/MCommands/MoveForwardCommand.h"
#include "GPPatterns/MCommands/MoveRightCommand.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AMyCharacter>(GetPawn());

	CommandMap.Add(EInputAction::Jump, MakeShareable(new JumpCommand()));
	CommandMap.Add(EInputAction::MoveForward, MakeShareable(new MoveForwardCommand()));
	CommandMap.Add(EInputAction::MoveRight, MakeShareable(new MoveRightCommand()));

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(PlayerMappingContext, 0);
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EIC = CastChecked<UEnhancedInputComponent>(InputComponent);

	if(EIC)
	{
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::OnJumpAction);
		EIC->BindAction(MoveForwardAction, ETriggerEvent::Started, this, &ThisClass::OnMoveForwardAction);
		EIC->BindAction(MoveRightAction, ETriggerEvent::Started, this, &ThisClass::OnMoveRightAction);
	}
}

void AMyPlayerController::OnJumpAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::Jump]->Execute(Character);
	}
}

void AMyPlayerController::OnMoveForwardAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::MoveForward]->Execute(Character, ActionValue.Get<float>());
	}
}

void AMyPlayerController::OnMoveRightAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::MoveRight]->Execute(Character, ActionValue.Get<float>());
	}
}
