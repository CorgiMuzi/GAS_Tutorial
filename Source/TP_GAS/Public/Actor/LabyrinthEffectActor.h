// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "LabyrinthEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApplyPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovePolicy : uint8
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class TP_GAS_API ALabyrinthEffectActor : public AActor
{
	GENERATED_BODY()

public:
	ALabyrinthEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* ApplyingTarget, const TSubclassOf<UGameplayEffect> ApplyingEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	bool bDestroyOnEffectRemoved = false;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float ActorLevel = 1.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	EEffectApplyPolicy InstantEffectApplyPolicy = EEffectApplyPolicy::DoNotApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	EEffectApplyPolicy DurationEffectApplyPolicy = EEffectApplyPolicy::DoNotApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	EEffectApplyPolicy InfiniteEffectApplyPolicy = EEffectApplyPolicy::DoNotApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	EEffectRemovePolicy InfiniteEffectRemovePolicy = EEffectRemovePolicy::RemoveOnEndOverlap;
};
