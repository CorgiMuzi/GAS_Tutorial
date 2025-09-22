// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/WidgetController/LabyrinthWidgetController.h"
#include "OverlayWidgetController.generated.h"

USTRUCT(BlueprintType)
struct FGameplayTagDebugInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag TargetTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ULabyrinthUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> Image;
};

struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVitalAttributeReducedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayTagDebugSignature, FGameplayTagDebugInfo, DebugInfo);

UCLASS(BlueprintType, Blueprintable)
class TP_GAS_API UOverlayWidgetController : public ULabyrinthWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangedSignature OnHealthChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangedSignature OnMaxHealthChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangedSignature OnManaChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangedSignature OnMaxManaChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnVitalAttributeReducedSignature OnVitalAttributeReducedDelegate;

	UPROPERTY(BlueprintAssignable, Category="GAS|Debug")
	FGameplayTagDebugSignature GameplayTagDebugMessageDelegate;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Widget Data")
	TObjectPtr<UDataTable> TagInfoDataTable;

	template<typename T>
	T* GetDataTableRowByTag(const UDataTable* DataTable, const FGameplayTag& Tag);
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(const UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
