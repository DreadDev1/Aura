// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  Singleton containing native Gameplay Tags
 */
USTRUCT(BlueprintType)
struct FBaseGameplayTags
{
public:
	static const FBaseGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();
	

protected:

private:
	static FBaseGameplayTags GameplayTags;
};
