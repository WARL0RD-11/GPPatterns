

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */

class UInputAction;
class ICommand;
class UUserWidget;


UENUM()
enum class EInputAction : uint8
{
	None,
	Jump,
	MoveForward,
	MoveBackward,
	MoveRight,
	MoveLeft,
};


UCLASS()
class GPPATTERNS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

public:
	class AMyCharacter* Character;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UEnhancedInputComponent> EIC;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveForwardAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveBackwardAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveRightAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveLeftAction;

	UFUNCTION(BlueprintCallable)
	void RebindKey(UInputAction* Action, FKey NewKey);


private:

	TMap<EInputAction, TSharedPtr<ICommand>> CommandMap;

	void OnJumpAction(const FInputActionValue& ActionValue);
	void OnMoveForwardAction(const FInputActionValue& ActionValue);
	void OnMoveBackwardAction(const FInputActionValue& ActionValue);
	void OnMoveRightAction(const FInputActionValue& ActionValue);
	void OnMoveLeftAction(const FInputActionValue& ActionValue);
};
