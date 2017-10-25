// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "BaseWeapon.h"
#include "Struct_AttachInfo.generated.h"

/**
 * 
 */

USTRUCT()
struct FAttachInfo
{
	GENERATED_BODY()

	UPROPERTY()
	bool inUse;

	UPROPERTY()
	EAttachPoint AttachPoint;

	UPROPERTY()
	ABaseWeapon* WeaponRef;

	FAttachInfo()
	{
		inUse = false;
		AttachPoint = EAttachPoint::AP_Sheath;
		WeaponRef = 0;
	}
};
