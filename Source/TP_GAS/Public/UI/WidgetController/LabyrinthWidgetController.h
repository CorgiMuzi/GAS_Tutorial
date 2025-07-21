// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "LabyrinthWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class TP_GAS_API ULabyrinthWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
