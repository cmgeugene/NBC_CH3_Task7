// Fill out your copyright notice in the Description page of Project Settings.

#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "TaskNo7.h"
#include "TaskNo7PlayerController.h"

ASpartaGameMode::ASpartaGameMode()
{
	DefaultPawnClass = ATaskNo7::StaticClass();
	PlayerControllerClass = ATaskNo7PlayerController::StaticClass();
}
