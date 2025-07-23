// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/LabyrinthAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValue()
{
	const ULabyrinthAttributeSet* LabyrinthAttributeSet = CastChecked<ULabyrinthAttributeSet>(AttributeSet);

	OnHealthChangedDelegate.Broadcast(LabyrinthAttributeSet->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(LabyrinthAttributeSet->GetMaxHealth());
	OnManaChangedDelegate.Broadcast(LabyrinthAttributeSet->GetMana());
	OnMaxManaChangedDelegate.Broadcast(LabyrinthAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const ULabyrinthAttributeSet* LabyrinthAttributeSet = CastChecked<ULabyrinthAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetHealthAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::OnHealthChanged
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetMaxHealthAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::OnMaxHealthChanged
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetManaAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::OnManaChanged
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetMaxManaAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::OnMaxManaChanged
	);
}

void UOverlayWidgetController::OnHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChangedDelegate.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChangedDelegate.Broadcast(Data.NewValue);
}
