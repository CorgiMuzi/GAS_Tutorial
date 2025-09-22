// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/LabyrinthAbilitySystemComponent.h"
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
		LabyrinthAttributeSet->GetHealthAttribute()).AddLambda(
			[this] (const FOnAttributeChangeData& Data)
			{
				if (Data.OldValue > Data.NewValue)
				{
					OnVitalAttributeReducedDelegate.Broadcast(Data.NewValue);
				}

				OnHealthChangedDelegate.Broadcast(Data.NewValue);
			}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			if (Data.OldValue > Data.NewValue) 	
			{
				OnVitalAttributeReducedDelegate.Broadcast(Data.NewValue);
			}

			OnManaChangedDelegate.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		LabyrinthAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChangedDelegate.Broadcast(Data.NewValue);
		}
	);

	Cast<ULabyrinthAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTag.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (FGameplayTag Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FGameplayTagDebugInfo* Row = GetDataTableRowByTag<FGameplayTagDebugInfo>(
						TagInfoDataTable, Tag);
					GameplayTagDebugMessageDelegate.Broadcast(*Row);
				}
			}
		}
	);
}