// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "Framework/AbilitySystem/BaseAbilitySystemComponent.h"
#include "Framework/AbilitySystem/Attributes/BaseAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBaseAttributeSet* BaseAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BaseAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BaseAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(BaseAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(BaseAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBaseAttributeSet* AuraAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetHealthAttribute()).AddLambda([this] (const FOnAttributeChangeData& Data)
	{OnHealthChanged.Broadcast(Data.NewValue);});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxHealthAttribute()).AddLambda([this] (const FOnAttributeChangeData& Data)
	{OnMaxHealthChanged.Broadcast(Data.NewValue);});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetManaAttribute()).AddLambda([this] (const FOnAttributeChangeData& Data)
	{OnManaChanged.Broadcast(Data.NewValue);});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxManaAttribute()).AddLambda([this] (const FOnAttributeChangeData& Data)
	{OnMaxManaChanged.Broadcast(Data.NewValue);});

	Cast<UBaseAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this] (const FGameplayTagContainer AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if(Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
                  	MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}	
		}
		);
}
