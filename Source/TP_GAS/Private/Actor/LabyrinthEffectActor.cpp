// © 2025 CorgiMuzi <kjhcorgi99@gmail.com>


#include "Actor/LabyrinthEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/LabyrinthAttributeSet.h"
#include "Components/SphereComponent.h"

ALabyrinthEffectActor::ALabyrinthEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	PickupArea = CreateDefaultSubobject<USphereComponent>("Pickup Area");
	PickupArea->SetupAttachment(GetRootComponent());
}

void ALabyrinthEffectActor::BeginPlay()
{
	Super::BeginPlay();

	if (PickupArea)
	{
		PickupArea->OnComponentBeginOverlap.AddDynamic(this, &ALabyrinthEffectActor::OnOverlap);
		PickupArea->OnComponentEndOverlap.AddDynamic(this, &ALabyrinthEffectActor::EndOverlap);
	}
}

void ALabyrinthEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const ULabyrinthAttributeSet* LabyrinthAttributeSet = Cast<ULabyrinthAttributeSet>(ASInterface->GetAbilitySystemComponent()->GetAttributeSet(ULabyrinthAttributeSet::StaticClass()));
		ULabyrinthAttributeSet* MutableLabyrinthAS = const_cast<ULabyrinthAttributeSet*>(LabyrinthAttributeSet);
		MutableLabyrinthAS->SetHealth(MutableLabyrinthAS->GetHealth() + 25.f);
		Destroy();
	}
}

void ALabyrinthEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
