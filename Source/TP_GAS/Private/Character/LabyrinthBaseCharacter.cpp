// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/LabyrinthBaseCharacter.h"

ALabyrinthBaseCharacter::ALabyrinthBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponSocket")); 
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

UAbilitySystemComponent* ALabyrinthBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALabyrinthBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

