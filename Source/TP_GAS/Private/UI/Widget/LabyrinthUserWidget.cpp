// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "UI/Widget/LabyrinthUserWidget.h"

void ULabyrinthUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnWidgetControllerSet();
}
