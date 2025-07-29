// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "AbilitySystem/LabyrinthAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"

ULabyrinthAttributeSet::ULabyrinthAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(100.f);
}

void ULabyrinthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void ULabyrinthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}

}

void ULabyrinthAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	const FGameplayEffectContextHandle& EffectSpecHandle = Data.EffectSpec.GetEffectContext();
	const UAbilitySystemComponent* SourceASC = EffectSpecHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(SourceASC) && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* SourceAvatarActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
		const AController* SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
		if (SourceController == nullptr && SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(SourceAvatarActor))
			{
				SourceController = Pawn->GetController();
			}
		}

		if (SourceController)
		{
			ACharacter* SourceCharacter = Cast<ACharacter>(SourceController->GetPawn());
		}
	}
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
