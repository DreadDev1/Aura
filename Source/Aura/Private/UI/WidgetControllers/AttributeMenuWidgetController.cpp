// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/AttributeMenuWidgetController.h"

#include "BaseGameplayTags.h"
#include "Framework/AbilitySystem/Attributes/BaseAttributeSet.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UBaseAttributeSet* AS = CastChecked<UBaseAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		FBaseAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
}
