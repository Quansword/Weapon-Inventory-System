// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "Enum_AttachPoint.generated.h"

/**
 * 
 */

UENUM(BlueprintType) // This tells us what type of weapon we're dealing with.
enum class EAttachPoint : uint8
{
	AP_Sheath		UMETA(DisplayName = "Sheath"),
	AP_Gear			UMETA(DisplayName = "Gear"),
	AP_Secondary	UMETA(DisplayName = "Secondary")
};

UCLASS()
class WEAPONSYSTEM_CODE_API UEnum_AttachPoint : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EAttachPoint AttachPoint;
	
};
