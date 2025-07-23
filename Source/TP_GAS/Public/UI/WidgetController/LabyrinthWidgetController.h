// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "LabyrinthWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType) 
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() : PlayerController(nullptr), PlayerState(nullptr), AbilitySystem(nullptr), AttributeSet(nullptr){}
	FWidgetControllerParams(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystem, UAttributeSet* InAttributeSet)
	: PlayerController(InPlayerController), PlayerState(InPlayerState), AbilitySystem(InAbilitySystem), AttributeSet(InAttributeSet) {}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystem;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;
};

UCLASS()
class TP_GAS_API ULabyrinthWidgetController : public UObject
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValue();
	virtual void BindCallbacksToDependencies();

	UFUNCTION(BlueprintCallable)
	void InitWidgetController(const FWidgetControllerParams& WidgetControllerParams);


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
