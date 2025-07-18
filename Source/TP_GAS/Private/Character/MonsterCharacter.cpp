// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/MonsterCharacter.h"

#include "AbilitySystem/LabyrinthAbilitySystemComponent.h"
#include "AbilitySystem/LabyrinthAttributeSet.h"

void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULabyrinthAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<ULabyrinthAttributeSet>(TEXT("AttributeSet"));
}

void AMonsterCharacter::EnableHighlight()
{

}

void AMonsterCharacter::DisableHighlight()
{

}
