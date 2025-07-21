// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LabyrinthUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TP_GAS_API ULabyrinthUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
};
