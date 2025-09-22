// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "AbilitySystem/LabyrinthAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"

ULabyrinthAttributeSet::ULabyrinthAttributeSet()
{
	InitHealth(50.f);
	InitMana(50.f);
}

void ULabyrinthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Vigor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Luck, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, CriticalResistChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, Evasion, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, ProcChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULabyrinthAttributeSet, ResistChance, COND_None, REPNOTIFY_Always);

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

	FEffectProperties Props;
	SetGameplayEffectProperties(Data, Props);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}

void ULabyrinthAttributeSet::SetGameplayEffectProperties(const FGameplayEffectModCallbackData& Data,
                                                         FEffectProperties& Props)
{
	Props.EffectContextHandle = Data.EffectSpec.GetEffectContext();
	Props.SourceAbilitySystem = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceAbilitySystem) && Props.SourceAbilitySystem->AbilityActorInfo.IsValid() && Props.
		SourceAbilitySystem->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceAbilitySystem->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceAbilitySystem->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}

		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetAbilitySystem = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
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

void ULabyrinthAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Strength, OldStrength);
}

void ULabyrinthAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Intelligence, OldIntelligence);
}

void ULabyrinthAttributeSet::OnRep_Resilience(const FGameplayAttributeData& OldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Resilience, OldResilience);
}

void ULabyrinthAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Vigor, OldVigor);
}

void ULabyrinthAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldLuck) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Luck, OldLuck);
}

void ULabyrinthAttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, HealthRegen, OldHealthRegen);
}

void ULabyrinthAttributeSet::OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, ManaRegen, OldManaRegen);
}

void ULabyrinthAttributeSet::OnRep_Evasion(const FGameplayAttributeData& OldEvasion) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Evasion, OldEvasion);
}

void ULabyrinthAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, Armor, OldArmor);
}

void ULabyrinthAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, ArmorPenetration, OldArmorPenetration);
}

void ULabyrinthAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, CriticalHitChance, OldCriticalHitChance);
}

void ULabyrinthAttributeSet::OnRep_CriticalResistChance(const FGameplayAttributeData& OldCriticalResistChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, CriticalResistChance, OldCriticalResistChance);
}

void ULabyrinthAttributeSet::OnRep_ProcChance(const FGameplayAttributeData& OldProcChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, ProcChance, OldProcChance);
}

void ULabyrinthAttributeSet::OnRep_ResistChance(const FGameplayAttributeData& OldResistChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabyrinthAttributeSet, ResistChance, OldResistChance);
}
