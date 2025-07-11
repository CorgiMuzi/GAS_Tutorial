// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeeperController.generated.h"

class IHighlightInterface;
class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

UCLASS()
class TP_GAS_API AKeeperController : public APlayerController
{
	GENERATED_BODY()
public:
	AKeeperController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void TraceUnderCursor();
	void Move(const FInputActionValue& InputActionValue);

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> KeeperContext;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY()
	TScriptInterface<IHighlightInterface> LastHighlight;

	UPROPERTY()
	TScriptInterface<IHighlightInterface> CurrentHighlight;
};
