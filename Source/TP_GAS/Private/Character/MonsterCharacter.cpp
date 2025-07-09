// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/MonsterCharacter.h"

void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AMonsterCharacter::EnableHighlight()
{

}

void AMonsterCharacter::DisableHighlight()
{

}
