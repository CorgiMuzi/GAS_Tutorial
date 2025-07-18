// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MonsterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AMonsterCharacter;
/**
 * 
 */
UCLASS()
class TP_GAS_API UMonsterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UMonsterAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	bool IsTryingToMove() const;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AMonsterCharacter> Monster;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCharacterMovementComponent> MonsterMovement;

	UPROPERTY(Transient, BlueprintReadOnly)
	float Speed{0.f};

	UPROPERTY(Transient, BlueprintReadOnly)
	bool IsFalling{false};

	UPROPERTY(Transient, BlueprintReadOnly)
	bool ShouldMove{true};
};
