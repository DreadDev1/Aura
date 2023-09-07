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
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	Cast<UBaseAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this] (const FGameplayTagContainer AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);

				FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
			}	
		}
		);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
