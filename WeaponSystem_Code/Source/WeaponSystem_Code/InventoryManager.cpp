// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryManager.h"


// Sets default values for this component's properties
UInventoryManager::UInventoryManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryManager::BeginPlay()
{
	Super::BeginPlay();

	InitSocketStates();
	
}


// Called every frame
void UInventoryManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UInventoryManager::InitSocketStates()
{
	FAttachInfo sheath;
	FAttachInfo gear;
	FAttachInfo secondary;

	gear.AttachPoint = EAttachPoint::AP_Gear;
	secondary.AttachPoint = EAttachPoint::AP_Secondary;

	SocketStates.Add(sheath);
	SocketStates.Add(gear);
	SocketStates.Add(secondary);
}

void UInventoryManager::SetEquippedWeapon(ABaseWeapon* Weapon)
{
	EquippedWeapon = Weapon;
}

void UInventoryManager::SetEquippedOffhand(ABaseWeapon* Offhand)
{
	EquippedOffhand = Offhand;
}

void UInventoryManager::ClearEquippedWeapon()
{
	EquippedWeapon = 0;
}

TTuple<bool, ABaseWeapon*> UInventoryManager::GetCurrentEquippedWeapon()
{
	return TTuple<bool, ABaseWeapon*>(IsValid(EquippedWeapon), EquippedWeapon);
}

TTuple<EAttachPoint, bool> UInventoryManager::IsSocketFree(ABaseWeapon* ForWeapon)
{
	EAttachPoint Local_SocketPoint = EAttachPoint::AP_Sheath;
	bool Local_SocketFound = false;

	for (int i = 0; i < 3; i++)
	{
		if (SocketStates[i].inUse == false && SocketStates[i].AttachPoint == ForWeapon->SetAttachPoint)
		{
			Local_SocketFound = true;
			Local_SocketPoint = ForWeapon->SetAttachPoint;
		}
	}

	return TTuple<EAttachPoint, bool>(Local_SocketPoint, Local_SocketFound);
}

void UInventoryManager::MarkSocketAsInUse(EAttachPoint Point, ABaseWeapon* Weapon)
{
	UINT Local_Index = 0;
	FAttachInfo Local_NewAttachInfo;

	for (int i = 0; i < 3; i++)
	{
		if (SocketStates[i].AttachPoint == Point)
		{
			Local_Index = i;
			Local_NewAttachInfo.inUse = true;
			Local_NewAttachInfo.AttachPoint = Point;
			Local_NewAttachInfo.WeaponRef = Weapon;
			break;
		}
	}

	SocketStates[Local_Index] = Local_NewAttachInfo;
}

void UInventoryManager::MarkSocketAsFree(EAttachPoint Point)
{
	UINT Local_Index = 0;
	FAttachInfo Local_NewAttachInfo;

	for (int i = 0; i < 3; i++)
	{
		if (SocketStates[i].AttachPoint == Point)
		{
			Local_Index = i;
			Local_NewAttachInfo.AttachPoint = Point;
			break;
		}
	}

	SocketStates[Local_Index] = Local_NewAttachInfo;
}

ABaseWeapon* UInventoryManager::GetWeaponInSocket(EAttachPoint Point)
{
	for (int i = 0; i < 3; i++)
	{
		if (SocketStates[i].inUse == true && SocketStates[i].AttachPoint == Point)
		{
			return SocketStates[i].WeaponRef;
		}
	}

	return 0;
}

void UInventoryManager::AddToInventory(ABaseWeapon* Weapon)
{
	InventoryItems.Add(Weapon);

	TTuple<EAttachPoint, bool> SocketFree = IsSocketFree(Weapon);

	if (SocketFree.Get<1>())
	{
		MarkSocketAsInUse(SocketFree.Get<0>(), Weapon);
		Weapon->AttachWeaponToCharacter(ULib_WeaponLibrary::GetSocketNameByPoint(SocketFree.Get<0>()));
	}
}

void UInventoryManager::Equip(ABaseWeapon* Weapon)
{
	SetEquippedWeapon(Weapon);
}

void UInventoryManager::EquipOffhand(ABaseWeapon* Offhand_Weapon)
{
	SetEquippedOffhand(Offhand_Weapon);
	MarkSocketAsFree(EAttachPoint::AP_Sheath);
}

void UInventoryManager::UnEquip()
{
	ClearEquippedWeapon();
}
