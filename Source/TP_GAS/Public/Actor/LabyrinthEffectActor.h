// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LabyrinthEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class TP_GAS_API ALabyrinthEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	ALabyrinthEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable) 
	void ApplyEffectToTarget(AActor* ApplyingTarget, const TSubclassOf<UGameplayEffect> ApplyingEffectClass) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
