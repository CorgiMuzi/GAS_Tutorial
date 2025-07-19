// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Player/KeeperPlayerState.h"

#include "AbilitySystem/LabyrinthAbilitySystemComponent.h"
#include "AbilitySystem/LabyrinthAttributeSet.h"

AKeeperPlayerState::AKeeperPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<ULabyrinthAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<ULabyrinthAttributeSet>(TEXT("AttributeSet"));

	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AKeeperPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}