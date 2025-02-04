// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	: InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr),
	InputMappingContext_UI(nullptr),
	ChangeInputMappingContextAction(nullptr),
	bDefaultContext(true)
{
}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
				Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void ASpartaPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (ChangeInputMappingContextAction)
		{
			EnhancedInputComponent->BindAction(ChangeInputMappingContextAction, ETriggerEvent::Triggered, this, &ASpartaPlayerController::ChangeIMC);
		}
		
	}
}

void ASpartaPlayerController::ChangeIMC()
{
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			
			if (bDefaultContext)
			{
				Subsystem->RemoveMappingContext(InputMappingContext);
				Subsystem->AddMappingContext(InputMappingContext_UI, 0);
				UE_LOG(LogTemp, Warning, TEXT("UI On"));
			}
			else if (!bDefaultContext)
			{
				Subsystem->RemoveMappingContext(InputMappingContext_UI);
				Subsystem->AddMappingContext(InputMappingContext, 0);
				UE_LOG(LogTemp, Warning, TEXT("UI Off"));
			}
			bDefaultContext = !bDefaultContext;
		}
	}
}