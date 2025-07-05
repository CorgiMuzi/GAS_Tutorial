// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LabyrinthBaseCharacter.generated.h"

UCLASS()
class TP_GAS_API ALabyrinthBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALabyrinthBaseCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
};
