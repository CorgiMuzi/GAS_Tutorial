// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Actor/LabyrinthEffectActor.h"

#include "AbilitySystem/LabyrinthAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"

ALabyrinthEffectActor::ALabyrinthEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}

void ALabyrinthEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALabyrinthEffectActor::ApplyEffectToTarget(AActor* ApplyingTarget, TSubclassOf<UGameplayEffect> ApplyingEffectClass) const
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(ApplyingTarget);
	if (TargetASC == nullptr) return;

	check(ApplyingEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(
		ApplyingEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
