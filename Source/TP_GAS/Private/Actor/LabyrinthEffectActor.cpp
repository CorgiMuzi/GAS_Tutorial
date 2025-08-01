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

void ALabyrinthEffectActor::ApplyEffectToTarget(AActor* ApplyingTarget,
                                                const TSubclassOf<UGameplayEffect> ApplyingEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(ApplyingTarget);
	if (TargetASC == nullptr) return;

	check(ApplyingEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(
		ApplyingEffectClass, ActorLevel, EffectContextHandle);

	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(
		*EffectSpecHandle.Data.Get());

	const FActiveGameplayEffect* ActiveEffect = TargetASC->GetActiveGameplayEffect(ActiveEffectHandle);
	const bool bIsInfinite = ActiveEffect && ActiveEffect->Spec.Def &&
		ActiveEffect->Spec.Def->DurationPolicy == EGameplayEffectDurationType::Infinite;

	if (bIsInfinite && InfiniteEffectRemovePolicy != EEffectRemovePolicy::DoNotRemove)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
}

void ALabyrinthEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplyPolicy == EEffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}

	if (DurationEffectApplyPolicy == EEffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}

	if (InfiniteEffectApplyPolicy == EEffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

void ALabyrinthEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplyPolicy == EEffectApplyPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}

	if (DurationEffectApplyPolicy == EEffectApplyPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}

	if (InfiniteEffectApplyPolicy == EEffectApplyPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}

	if (InfiniteEffectRemovePolicy == EEffectRemovePolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;

		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for (auto HandlePair : ActiveEffectHandles)
		{
			if (HandlePair.Value == TargetASC)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
				HandlesToRemove.Add(HandlePair.Key);
			}
		}

		for (FActiveGameplayEffectHandle& Handle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}
