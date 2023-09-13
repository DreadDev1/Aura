// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayTags.h"
#include "GameplayTagsManager.h" 

FBaseGameplayTags FBaseGameplayTags::GameplayTags;

void FBaseGameplayTags::InitializeNativeGameplayTags()
{
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attribute.Secondary.Armor"), FString("Reduces Damage taken. Improves Block Chance")));
}
