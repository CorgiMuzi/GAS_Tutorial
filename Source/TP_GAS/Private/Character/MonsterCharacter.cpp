// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/MonsterCharacter.h"

#include "AbilitySystem/LabyrinthAbilitySystemComponent.h"
#include "AbilitySystem/LabyrinthAttributeSet.h"

AMonsterCharacter::AMonsterCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULabyrinthAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<ULabyrinthAttributeSet>(TEXT("AttributeSet"));
}

void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystem();
}


void AMonsterCharacter::InitAbilitySystem()
{
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AMonsterCharacter::EnableHighlight()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(1);
}

void AMonsterCharacter::DisableHighlight()
{
	GetMesh()->SetRenderCustomDepth(false);
}