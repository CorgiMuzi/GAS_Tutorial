// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Controller/KeeperController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interact/HighlightInterface.h"

AKeeperController::AKeeperController()
{
	bReplicates = true;
}

void AKeeperController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	TraceUnderCursor();
}

void AKeeperController::BeginPlay()
{
	Super::BeginPlay();

	check(KeeperContext);

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubsystem->AddMappingContext(KeeperContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}

void AKeeperController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKeeperController::Move);
}

void AKeeperController::TraceUnderCursor()
{
	FHitResult HitResult;

	GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), false, HitResult);

	if (!HitResult.bBlockingHit) return;

	LastHighlight = CurrentHighlight;
	CurrentHighlight = HitResult.GetActor();

	if (LastHighlight)
	{
		if (LastHighlight != CurrentHighlight)
		{
			if (CurrentHighlight) CurrentHighlight->EnableHighlight();
			LastHighlight->DisableHighlight();
		}
	}else
	{
		if (CurrentHighlight)
		{
			CurrentHighlight->EnableHighlight();
		}
	}
}

void AKeeperController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputValue = InputActionValue.Get<FVector2D>();
	const FRotator ControllerRotation = GetControlRotation();
	const FRotator YawRotation(0.f, ControllerRotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	}
}
