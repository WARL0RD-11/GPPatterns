

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
};


UCLASS()
class GPPATTERNS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;

private:
	TMap<EInputAction, TSharedPtr<ICommand>> CommandMap;

	void OnJumpAction(const FInputActionValue& ActionValue);
};
