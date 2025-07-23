// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "UI/WidgetController/LabyrinthWidgetController.h"

void ULabyrinthWidgetController::BroadcastInitialValue()
{

}

void ULabyrinthWidgetController::BindCallbacksToDependencies()
{
}

void ULabyrinthWidgetController::InitWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystem;
	AttributeSet = WidgetControllerParams.AttributeSet;
}
