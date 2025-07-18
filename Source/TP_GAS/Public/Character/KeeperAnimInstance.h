// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KeeperAnimInstance.generated.h"

class UCharacterMovementComponent;
class AKeeperCharacter;

UENUM(BlueprintType)
enum class EIdleState : uint8
{
	EIS_Relaxed UMETA(DisplayName="Relaxed"),
	EIS_Alert UMETA(DisplayName="Alert"),
	EIS_CombatReady UMETA(DisplayName="CombatReady"),

	EIS_MAX UMETA(DisplayName="Max")
};


UCLASS()
class TP_GAS_API UKeeperAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UKeeperAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	bool IsTryingToMove() const;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AKeeperCharacter> KeeperCharacter;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCharacterMovementComponent> KeeperMovement;

	UPROPERTY(BlueprintReadOnly)
	EIdleState IdleState{EIdleState::EIS_Relaxed};

	UPROPERTY(Transient, BlueprintReadOnly)
	float Speed{0.f};

	UPROPERTY(Transient,BlueprintReadOnly)
	float Acceleration{0.f};

	UPROPERTY(Transient, BlueprintReadOnly)
	bool IsFalling{false};

	UPROPERTY(Transient, BlueprintReadOnly)
	bool ShouldMove{true};
};
