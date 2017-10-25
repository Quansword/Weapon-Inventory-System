// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWeapon.h"
#include "WeaponSystem_CodeCharacter.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FText WeaponName = FText::FromString("");
	FName EquipSocketName = FName(TEXT("Hand_Right"));
	EAttachPoint SetAttachPoint = EAttachPoint::AP_Sheath;
	EAttachPoint CurrentAttachPoint = EAttachPoint::AP_Sheath;
	EWeaponType WeaponType = EWeaponType::WE_Primary;
	bool isEquipped = false;
	bool isEquippedOffhand = false;
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::AttachWeaponToCharacter(FName SocketName)
{
	OwningChar = Cast<AWeaponSystem_CodeCharacter>(GetOwner());
	USceneComponent* SceneComp = Cast<USceneComponent>(OwningChar->GetMesh());
	if (SceneComp->DoesSocketExist(SocketName))
	{
		AttachToComponent(SceneComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);
	}
	CurrentAttachPoint = ULib_WeaponLibrary::GetSocketPointByName(SocketName);
}

void ABaseWeapon::Equip()
{
	OwningChar = Cast<AWeaponSystem_CodeCharacter>(GetOwner());
	USceneComponent* SceneComp = Cast<USceneComponent>(OwningChar->GetMesh());
	AttachToComponent(SceneComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale, EquipSocketName);
	isEquipped = true;
}

void ABaseWeapon::EquipOffhand()
{
	OwningChar = Cast<AWeaponSystem_CodeCharacter>(GetOwner());
	USceneComponent* SceneComp = Cast<USceneComponent>(OwningChar->GetMesh());
	AttachToComponent(SceneComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale, EquipSocketName);
	isEquippedOffhand = true;
}

void ABaseWeapon::UnEquip()
{
	OwningChar = Cast<AWeaponSystem_CodeCharacter>(GetOwner());
	USceneComponent* SceneComp = Cast<USceneComponent>(OwningChar->GetMesh());
	FName sockName = ULib_WeaponLibrary::GetSocketNameByPoint(CurrentAttachPoint);
	AttachToComponent(SceneComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale, sockName);
	isEquipped = false;
}
