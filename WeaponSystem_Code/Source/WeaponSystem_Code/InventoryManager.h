// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Struct_AttachInfo.h"
#include "InventoryManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_CODE_API UInventoryManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	ABaseWeapon* EquippedWeapon;
	ABaseWeapon* EquippedOffhand;
	TArray<ABaseWeapon*> InventoryItems;
	TArray<FAttachInfo> SocketStates;

	void InitSocketStates();
	void SetEquippedWeapon(ABaseWeapon* Weapon);
	void SetEquippedOffhand(ABaseWeapon* Offhand);
	void ClearEquippedWeapon();
	TTuple<bool, ABaseWeapon*> GetCurrentEquippedWeapon();
	TTuple<EAttachPoint, bool> IsSocketFree(ABaseWeapon* ForWeapon);
	void MarkSocketAsInUse(EAttachPoint Point, ABaseWeapon* Weapon);
	void MarkSocketAsFree(EAttachPoint Point);
	ABaseWeapon* GetWeaponInSocket(EAttachPoint Point);

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "AddToInventory"))
	void AddToInventory(ABaseWeapon* Weapon);

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "Equip"))
	virtual void Equip(ABaseWeapon* Weapon);
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "EquipOffhand"))
	virtual void EquipOffhand(ABaseWeapon* Offhand_Weapon);
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "UnEquip"))
	virtual void UnEquip();
	
};
