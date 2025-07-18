// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/MonsterAnimInstance.h"

#include "Character/MonsterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UMonsterAnimInstance::UMonsterAnimInstance()
	: Speed(0.f), IsFalling(false), ShouldMove(false)
{
}

void UMonsterAnimInstance::NativeInitializeAnimation()
{
	// Super::NativeInitializeAnimation();

	if (APawn* PawnOwner = TryGetPawnOwner())
	{
		Monster = Cast<AMonsterCharacter>(PawnOwner);
	}

	if (Monster)
	{
		MonsterMovement = Monster->GetCharacterMovement();
	}
}

void UMonsterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Monster))
	{
		Speed = Monster->GetVelocity().Size2D();
	}

	if (IsValid(MonsterMovement))
	{
		IsFalling = MonsterMovement->IsFalling();
	}
}

void UMonsterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	ShouldMove = IsTryingToMove();
}

bool UMonsterAnimInstance::IsTryingToMove() const
{
	return Speed > 0.f && !IsFalling;
}
