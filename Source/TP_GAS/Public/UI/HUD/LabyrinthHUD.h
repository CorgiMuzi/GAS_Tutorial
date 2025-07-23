// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LabyrinthHUD.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class ULabyrinthUserWidget;

UCLASS()
class TP_GAS_API ALabyrinthHUD : public AHUD
{
	GENERATED_BODY()
public:
	void InitOverlay(APlayerController* NewPlayerController, APlayerState* NewPlayerState, UAbilitySystemComponent* NewAbilitySystem, UAttributeSet* NewAttributeSet);

	UPROPERTY()
	TObjectPtr<ULabyrinthUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);

private:
	UPROPERTY(EditDefaultsOnly, Category="Overlay")
	TSubclassOf<ULabyrinthUserWidget> OverlayWidgetClass;

	UPROPERTY(VisibleAnywhere, Category="Overlay")
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditDefaultsOnly, Category="Overlay")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
