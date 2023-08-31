// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseEffectActor.h"

#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "Framework/AbilitySystem/Attributes/BaseAttributeSet.h"

class UBaseAttributeSet;
// Sets default values
ABaseEffectActor::ABaseEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Actor Mesh");
	SetRootComponent(ActorMesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(ActorMesh);
	

}

void ABaseEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ABaseEffectActor::OnEndOverlap);
}

void ABaseEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UBaseAttributeSet* BaseAttributeSet = Cast<UBaseAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UBaseAttributeSet::StaticClass()));

		UBaseAttributeSet* MutableBaseAttributeSet = const_cast<UBaseAttributeSet*>(BaseAttributeSet);
		MutableBaseAttributeSet->SetHealth(BaseAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ABaseEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


