// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lib_WeaponLibrary.h"
#include "Enum_WeaponType.h"
#include "BaseWeapon.generated.h"

// Forward declaration of Character class

class AWeaponSystem_CodeCharacter;

UCLASS()
class WEAPONSYSTEM_CODE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

	AWeaponSystem_CodeCharacter* OwningChar;
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FText WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FName EquipSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	EAttachPoint SetAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	EAttachPoint CurrentAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	EWeaponType WeaponType;

	bool isEquipped;
	bool isEquippedOffhand;
	
	void AttachWeaponToCharacter(FName SocketName);

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "Equip"))
	virtual void Equip();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "EquipOffhand"))
	virtual void EquipOffhand();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "UnEquip"))
	virtual void UnEquip();
};
