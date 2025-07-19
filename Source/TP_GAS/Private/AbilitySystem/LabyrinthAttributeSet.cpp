// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "AbilitySystem/LabyrinthAttributeSet.h"
#include "Net/UnrealNetwork.h"

ULabyrinthAttributeSet::ULabyrinthAttributeSet()
{
	InitHealth(100.f);
}

void ULabyrinthAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void ULabyrinthAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Health, OldHealth);
}

void ULabyrinthAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, MaxHealth, OldMaxHealth);
}

void ULabyrinthAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Mana, OldMana);
}

void ULabyrinthAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, MaxMana, OldMaxMana);
}
