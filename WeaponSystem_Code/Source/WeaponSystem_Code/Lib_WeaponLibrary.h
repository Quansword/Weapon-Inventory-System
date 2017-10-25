// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Enum_AttachPoint.h"
#include "Lib_WeaponLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_CODE_API ULib_WeaponLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	static EAttachPoint GetSocketPointByName(FName SocketName);
	
	static FName GetSocketNameByPoint(EAttachPoint AttachPoint);
};
