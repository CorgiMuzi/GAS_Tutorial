// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Character/KeeperCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Controller/KeeperController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/KeeperPlayerState.h"
#include "UI/HUD/LabyrinthHUD.h"

AKeeperCharacter::AKeeperCharacter()
{
	SetupTopDownGameCameraView();

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->bInheritPitch = SpringArm->bInheritRoll = SpringArm->bInheritYaw = false;

	KeeperCamera = CreateDefaultSubobject<UCameraComponent>("KeeperCamera");
	KeeperCamera->SetupAttachment(SpringArm);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void AKeeperCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AKeeperCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystem();
}

void AKeeperCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystem();
}

void AKeeperCharacter::InitAbilitySystem()
{
	// Assert if player state is not valid
	AKeeperPlayerState* KeeperPlayerState = GetPlayerStateChecked<AKeeperPlayerState>();

	AbilitySystemComponent = KeeperPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(KeeperPlayerState, this);

	AttributeSet = KeeperPlayerState->GetAttributeSet();

	// Keeper Controller is valid on the local client only.
	// If I use 'check' or 'checkf' for controller, remote clients' controller will throw errors
	// That's why we use not check as KeeperPlayerState but if-statement
	if (AKeeperController* KeeperController = Cast<AKeeperController>(GetController()))
	{
		if (ALabyrinthHUD* LabyrinthHUD = Cast<ALabyrinthHUD>(KeeperController->GetHUD()))
		{
			LabyrinthHUD->InitOverlay(KeeperController, KeeperPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}

void AKeeperCharacter::SetupTopDownGameCameraView()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = bUseControllerRotationRoll = bUseControllerRotationYaw = false;
}


