// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "BaseInputConfig.h"
#include "BaseInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UBaseInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserClass, typename PressedFuncType, typename ReleaseFuncType, typename HeldFuncType>
void BindAbilityActions(const UBaseInputConfig* InputConfig, UserClass* Object,
	PressedFuncType PressedFunc,ReleaseFuncType ReleaseFunc, HeldFuncType HeldFunc);

};

template <class UserClass, typename PressedFuncType, typename ReleaseFuncType, typename HeldFuncType>
void UBaseInputComponent::BindAbilityActions(const UBaseInputConfig* InputConfig, UserClass* Object,
	PressedFuncType PressedFunc, ReleaseFuncType ReleaseFunc, HeldFuncType HeldFunc)
{
	check(InputConfig);

	for (const FBaseInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunc, Action.InputTag);
			}
			if (ReleaseFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleaseFunc, Action.InputTag);
			}
			if (HeldFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, Action.InputTag);
			}			
		}
	}
}
