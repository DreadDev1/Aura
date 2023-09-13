// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/AbilitySystem/Data/AttributeInfo.h"

FBaseAttributeInfo UAttributeInfo::FindAttributeInfoForTag(FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FBaseAttributeInfo Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find info for Attribute Tag [%s] on Attribute Info [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FBaseAttributeInfo();
}
