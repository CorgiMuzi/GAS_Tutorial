// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/KeeperAnimInstance.h"

#include "Character/KeeperCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UKeeperAnimInstance::UKeeperAnimInstance()
	: Speed(0.f), Acceleration(0.f), IsFalling(false), ShouldMove(false)
{
}

void UKeeperAnimInstance::NativeInitializeAnimation()
{
	// Super::NativeInitializeAnimation();
	if (APawn* PawnOwner = TryGetPawnOwner())
	{ 
		KeeperCharacter = Cast<AKeeperCharacter>(PawnOwner);
	}

	if (IsValid(KeeperCharacter))
	{
		KeeperMovement = KeeperCharacter->GetCharacterMovement();
	}
}

void UKeeperAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(KeeperCharacter))
	{
		Speed = KeeperCharacter->GetVelocity().Size2D();
	}

	if (IsValid(KeeperMovement))
	{
		Acceleration = KeeperMovement->GetCurrentAcceleration().Size2D();
		IsFalling = KeeperMovement->IsFalling();
	}
}

void UKeeperAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	ShouldMove = IsTryingToMove();
}

bool UKeeperAnimInstance::IsTryingToMove() const
{
	return Speed > 0.f && Acceleration > 0.f && !IsFalling;
}



