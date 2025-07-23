// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/LabyrinthBaseCharacter.h"

ALabyrinthBaseCharacter::ALabyrinthBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* ALabyrinthBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALabyrinthBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

