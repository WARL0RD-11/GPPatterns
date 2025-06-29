// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MyCharacter.h"

#include "GPPatterns/MCommands/JumpCommand.h"
#include "GPPatterns/MCommands/MoveForwardCommand.h"
#include "GPPatterns/MCommands/MoveBackwardCommand.h"
#include "GPPatterns/MCommands/MoveRightCommand.h"
#include "GPPatterns/MCommands/MoveLeftCommand.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AMyCharacter>(GetPawn());

	//DEFAULT MAPPINGS
	DefaultKeyMap.Add(JumpAction, EKeys::SpaceBar);
	DefaultKeyMap.Add(MoveForwardAction, EKeys::W);
	DefaultKeyMap.Add(MoveBackwardAction, EKeys::S);
	DefaultKeyMap.Add(MoveRightAction, EKeys::D);
	DefaultKeyMap.Add(MoveLeftAction, EKeys::A);

	//Dynamic Mappings
	CommandMap.Add(EInputAction::Jump, MakeShareable(new JumpCommand()));
	CommandMap.Add(EInputAction::MoveForward, MakeShareable(new MoveForwardCommand()));
	CommandMap.Add(EInputAction::MoveBackward, MakeShareable(new MoveBackwardCommand()));
	CommandMap.Add(EInputAction::MoveRight, MakeShareable(new MoveRightCommand()));
	CommandMap.Add(EInputAction::MoveLeft, MakeShareable(new MoveLeftCommand()));

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
		EIC->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveForwardAction);
		EIC->BindAction(MoveBackwardAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveBackwardAction);
		EIC->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveRightAction);
		EIC->BindAction(MoveLeftAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveLeftAction);
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

void AMyPlayerController::OnMoveBackwardAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::MoveBackward]->Execute(Character, ActionValue.Get<float>());
	}
}

void AMyPlayerController::OnMoveRightAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::MoveRight]->Execute(Character, ActionValue.Get<float>());
	}
}

void AMyPlayerController::OnMoveLeftAction(const FInputActionValue& ActionValue)
{
	if (Character)
	{
		CommandMap[EInputAction::MoveLeft]->Execute(Character, ActionValue.Get<float>());
	}
}

void AMyPlayerController::RebindKey(UInputAction* Action, FKey NewKey)
{	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer());

	if (!Subsystem) return;

	if (!PlayerMappingContext || !Action) return;

	TArray<FEnhancedActionKeyMapping> Mappings = PlayerMappingContext->GetMappings();

	for (int i = Mappings.Num() - 1 ; i >= 0; --i)
	{
		if (Mappings[i].Action == Action)
		{
			PlayerMappingContext->UnmapKey(Action, Mappings[i].Key);
		}
	}

	Subsystem->RemoveMappingContext(PlayerMappingContext);

	PlayerMappingContext->MapKey(Action, NewKey);

	Subsystem->AddMappingContext(PlayerMappingContext, 0);
}

void AMyPlayerController::ResetToDefaultKeys()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer());

	if (!Subsystem) return;

	TArray<FEnhancedActionKeyMapping> Mappings = PlayerMappingContext->GetMappings();

	for (int i = Mappings.Num() - 1; i >= 0; --i)
	{
		PlayerMappingContext->UnmapKey(Mappings[i].Action, Mappings[i].Key);
	}

	for (const TPair<UInputAction*, FKey>& Pair : DefaultKeyMap)
	{
		PlayerMappingContext->MapKey(Pair.Key, Pair.Value);
	}

	Subsystem->RemoveMappingContext(PlayerMappingContext);
	Subsystem->AddMappingContext(PlayerMappingContext, 0);

	UE_LOG(LogTemp, Warning, TEXT("Reset all bindings to default."));
}
