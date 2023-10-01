// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayTags.h"
#include "GameplayTagsManager.h" 

FBaseGameplayTags FBaseGameplayTags::GameplayTags;

void FBaseGameplayTags::InitializeNativeGameplayTags()
{
#pragma region Primary Attributes 
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Strength"), FString("Increases Physical Damage"));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Intelligence"), FString("Increases Magical Damage"));
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Resilience"), FString("Increases Armor and Armor Penetration"));
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Vigor"), FString("Increases Heath"));
#pragma endregion 
#pragma region Secondary Attributes 
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.Armor"), FString("Reduce Damage taken improves Block Chance"));
	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.ArmorPenetration"), FString("Ignores Percentage of enemy Armor, increases Crit Hit Chance"));
	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.BlockChance"), FString("Chance to cut incoming damage in half"));
	GameplayTags.Attributes_Secondary_CritHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CritHitChance"), FString("Chance to double damage plus critical hit bonus"));
	GameplayTags.Attributes_Secondary_CritHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CritHitDamage"), FString("Bonus damage added when Crit Hit is scored"));
	GameplayTags.Attributes_Secondary_CritHitResist = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.CritHitResist"), FString("Reduce Crit Hit Damage of attacking enemies"));
	GameplayTags.Attributes_Secondary_HealthRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.HealthRegen"), FString("Amount of Health regenerated every 1 second"));
	GameplayTags.Attributes_Secondary_ManaRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.ManaRegen"), FString("Amount of Mana regenerated every 1 second"));
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxHealth"), FString("Max Health for Player"));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Secondary.MaxMana"), FString("Max Mana for Player"));
#pragma endregion
#pragma region Input Action Buttons 
	GameplayTags.PrimaryAction_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.PrimaryAction_Input"), FString("Input Tag for Primary Action"));
	GameplayTags.SecondaryAction_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.SecondaryAction_Input"), FString("Input Tag for Secondary Action_"));
	GameplayTags.Key1_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.Key1_Input"), FString("Input Tag for 1 Key"));
	GameplayTags.Key2_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.Key2_Input"), FString("Input Tag for 2 Key"));
	GameplayTags.Key3_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.Key3_Input"), FString("Input Tag for 3 Key"));
	GameplayTags.Key4_Input = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName("InputTag.Key4_Input"), FString("Input Tag for 4 Key"));
#pragma endregion

}
