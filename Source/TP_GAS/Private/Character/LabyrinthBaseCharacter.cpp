// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/LabyrinthBaseCharacter.h"
#include "AbilitySystemComponent.h"

ALabyrinthBaseCharacter::ALabyrinthBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* ALabyrinthBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALabyrinthBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ALabyrinthBaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(EffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void ALabyrinthBaseCharacter::InitDefaultAttribute() const
{
	ApplyEffectToSelf(DefaultPrimaryAttribute,1.f);
	ApplyEffectToSelf(DefaultSecondaryAttribute, 1.f);
}
