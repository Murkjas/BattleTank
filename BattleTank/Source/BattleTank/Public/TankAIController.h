// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

protected:

	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "State")
	float AcceptanceRadius = 8000;

};
