// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LabyrinthAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

public:
	FEffectProperties(){}

	UPROPERTY()
	FGameplayEffectContextHandle EffectContextHandle;

	//=== Source ===
	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystem{nullptr};

	UPROPERTY()
	AActor* SourceAvatarActor{nullptr};

	UPROPERTY()
	AController* SourceController{nullptr};

	UPROPERTY()
	ACharacter* SourceCharacter{nullptr};
	// === End Source ===

	// === Target ===
	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystem{nullptr};

	UPROPERTY()
	AActor* TargetAvatarActor{nullptr};

	UPROPERTY()
	AController* TargetController{nullptr};

	UPROPERTY()
	ACharacter* TargetCharacter{nullptr};
	// === End Target ===
};

UCLASS()
class TP_GAS_API ULabyrinthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ULabyrinthAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
	void OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen) const;

	UFUNCTION()
	void OnRep_Evasion(const FGameplayAttributeData& OldEvasion) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalResistChance(const FGameplayAttributeData& OldCriticalResistChance) const;

	UFUNCTION()
	void OnRep_ProcChance(const FGameplayAttributeData& OldProcChance) const;

	UFUNCTION()
	void OnRep_ResistChance(const FGameplayAttributeData& OldResistChance) const;


	FEffectProperties EffectProperties;

	/*
	 * Vital attribute
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vital Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Vital Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Vital Attribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category="Vital Attribute")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, Category="Vital Attribute")
	FGameplayAttributeData GhostHealth;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, GhostHealth);

	/*
	 * Primary attributes
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Strength, Category="Primary Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Intelligence, Category="Primary Attribute")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Resilience, Category="Primary Attribute")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Vigor, Category="Primary Attribute")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Vigor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Luck, Category="Primary Attribute")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Luck);

	/*
	 * Secondary attribute
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HealthRegen, Category="Secondary Attribute")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, HealthRegen)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ManaRegen, Category="Secondary Attribute")
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, ManaRegen)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Evasion, Category="Secondary Attribute")
	FGameplayAttributeData Evasion;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Evasion);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Armor, Category="Secondary Attribtue")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ArmorPenetration, Category="Secondary Attribute")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, ArmorPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitChance, Category="Secondary Attribute")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalResistChance, Category="Secondary Attribute")
	FGameplayAttributeData CriticalResistChance;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, CriticalResistChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ProcChance, Category="Secondary Attribute")
	FGameplayAttributeData ProcChance;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, ProcChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ResistChance, Category="Secondary Attribute")
	FGameplayAttributeData ResistChance;
	ATTRIBUTE_ACCESSORS(ULabyrinthAttributeSet, ResistChance);

private:
	void SetGameplayEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
};
