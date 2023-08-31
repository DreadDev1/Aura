// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "BaseEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UCLASS()
class AURA_API ABaseEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseEffectActor();

protected:
	virtual void BeginPlay() override;

private:

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};