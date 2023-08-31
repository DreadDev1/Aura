// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/BaseCharacter.h"
#include "Framework/Interfaces/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ABaseCharacter, public IEnemyInterface

{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
};
