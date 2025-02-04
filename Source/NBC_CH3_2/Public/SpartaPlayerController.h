// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpartaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class NBC_CH3_2_API ASpartaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASpartaPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputMappingContext* InputMappingContext_UI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputAction* ChangeInputMappingContextAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputSettings")
	UInputAction* SprintAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputSettings")
	bool bDefaultContext;

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	UFUNCTION()
	void ChangeIMC();
};
