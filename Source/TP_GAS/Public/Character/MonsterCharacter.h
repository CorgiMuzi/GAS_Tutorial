// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Character/LabyrinthBaseCharacter.h"
#include "Interact/HighlightInterface.h"
#include "MonsterCharacter.generated.h"

UCLASS()
class TP_GAS_API AMonsterCharacter : public ALabyrinthBaseCharacter, public IHighlightInterface
{
	GENERATED_BODY()

public:
	AMonsterCharacter();

	// ====== Highlight Interface ======
	virtual void EnableHighlight() override;
	virtual void DisableHighlight() override;
	// ====== End Highlight Interface ======

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilitySystem() override;
};
