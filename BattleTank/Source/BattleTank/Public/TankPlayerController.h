// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	bool GetSightHitRayLocation(FVector& OutHitLocation) const;

	void AimTowardsCrosshair();
	
	virtual void SetPawn(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationX = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationY = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const;

};
