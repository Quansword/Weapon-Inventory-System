// Fill out your copyright notice in the Description page of Project Settings.

#include "Lib_WeaponLibrary.h"

EAttachPoint ULib_WeaponLibrary::GetSocketPointByName(FName SocketName)
{
	if (SocketName == FName(TEXT("Waist_Left")))
	{
		return EAttachPoint::AP_Sheath;
	}
	else if (SocketName == FName(TEXT("Thigh_Right")))
	{
		return EAttachPoint::AP_Gear;
	}
	else if (SocketName == FName(TEXT("Waist_Back")))
	{
		return EAttachPoint::AP_Secondary;
	}
	else
	{
		return EAttachPoint::AP_Sheath;
	}
}

FName ULib_WeaponLibrary::GetSocketNameByPoint(EAttachPoint AttachPoint)
{
	switch (AttachPoint)
	{
	case EAttachPoint::AP_Sheath:
		return FName(TEXT("Waist_Left"));
	case EAttachPoint::AP_Gear:
		return FName(TEXT("Thigh_Right"));
	case EAttachPoint::AP_Secondary:
		return FName(TEXT("Waist_Back"));
	default:
		return FName(TEXT("Waist_Left"));
	}
}
