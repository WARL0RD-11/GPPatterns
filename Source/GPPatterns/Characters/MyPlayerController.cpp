// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MyCharacter.h"

#include "GPPatterns/MCommands/JumpCommand.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AMyCharacter>(GetPawn());

	CommandMap.Add(EInputAction::Jump, MakeShareable(new JumpCommand()));

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

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);

	if(EIC)
	{
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::OnJumpAction);
	}
}

void AMyPlayerController::OnJumpAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::Jump]->Execute(Character);
	}
}
