// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "Enum_WeaponType.generated.h"

/**
 * 
 */

UENUM(BlueprintType) // This tells us what type of weapon we're dealing with.
enum class EWeaponType : uint8
{
	WE_Primary		UMETA(DisplayName = "Primary"),
	WE_PrimaryOff	UMETA(DisplayName = "Primary_Offhand"),
	WE_Secondary	UMETA(DisplayName = "Secondary"),
	WE_Gear			UMETA(DisplayName = "Gear")
};

UCLASS()
class WEAPONSYSTEM_CODE_API UEnum_WeaponType : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EWeaponType WeaponType;	
	
};
