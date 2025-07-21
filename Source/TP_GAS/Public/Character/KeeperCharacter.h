// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Character/LabyrinthBaseCharacter.h"
#include "KeeperCharacter.generated.h"


class AKeeperPlayerState;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TP_GAS_API AKeeperCharacter : public ALabyrinthBaseCharacter
{
	GENERATED_BODY()
public:
	AKeeperCharacter();
	virtual void PossessedBy(AController* NewController) override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilitySystem() override;

	UPROPERTY(EditDefaultsOnly, Category="Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

private:
	void SetupTopDownGameCameraView();
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UCameraComponent> KeeperCamera;
};
