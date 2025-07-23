// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "UI/HUD/LabyrinthHUD.h"
#include "UI/Widget/LabyrinthUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void ALabyrinthHUD::InitOverlay(APlayerController* NewPlayerController, APlayerState* NewPlayerState,
	UAbilitySystemComponent* NewAbilitySystem, UAttributeSet* NewAttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class in Labyrinth HUD is not assigned."))
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class in Labyrinth HUD is not assigned."))
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass, TEXT("OverlayWidget"));
	OverlayWidget = Cast<ULabyrinthUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(NewPlayerController, NewPlayerState, NewAbilitySystem, NewAttributeSet);
	ULabyrinthWidgetController* LabyrinthWidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(LabyrinthWidgetController);
	LabyrinthWidgetController->BroadcastInitialValue();

	Widget->AddToViewport();
}

UOverlayWidgetController* ALabyrinthHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this , OverlayWidgetControllerClass, TEXT("OverlayWidget"));
		OverlayWidgetController->InitWidgetController(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}