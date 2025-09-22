// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "AbilitySystem/LabyrinthAbilitySystemComponent.h"


void ULabyrinthAbilitySystemComponent::OnAbilitySystemInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ULabyrinthAbilitySystemComponent::OnEffectApplied);
}

void ULabyrinthAbilitySystemComponent::OnEffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                       const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	GameplayEffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTag.Broadcast(TagContainer);
}
