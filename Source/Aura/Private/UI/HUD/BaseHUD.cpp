// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/BaseHUD.h"
#include "UI/BaseUserWidget.h"

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
