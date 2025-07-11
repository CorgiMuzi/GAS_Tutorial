// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "Character/LabyrinthBaseCharacter.h"
#include "KeeperCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TP_GAS_API AKeeperCharacter : public ALabyrinthBaseCharacter
{
	GENERATED_BODY()
public:
	AKeeperCharacter();

protected:
	virtual void BeginPlay() override;

private:
	void SetupTopDownGameCameraView();

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UCameraComponent> KeeperCamera;
	
};
