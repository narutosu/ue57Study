// Fill out your copyright notice in the Description page of Project Settings.


#include "Stuty/AssetRegister/AssetRegisterFunctionLibrary.h"
#include "ue57.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet/KismetSystemLibrary.h"


void UAssetRegisterFunctionLibrary::PrintObjectAssetAllName(UObject* Object)
{
	PrintAssetAllName(FSoftObjectPath(Object));
}

void UAssetRegisterFunctionLibrary::PrintAssetAllName(FSoftObjectPath SoftPath)
{
	FAssetRegistryModule& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FAssetData Asset;
	AssetRegistry.Get().TryGetAssetByObjectPath(SoftPath, Asset);
	UObject* Object = SoftPath.TryLoad();

	UE_LOG(MyStudy, Warning, TEXT("Object.GetName:           %s"), *Object->GetName());
	UE_LOG(MyStudy, Warning, TEXT("ObjectSoft:               %s"), *FSoftObjectPath(Object).ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.ObjectPath:     %s  deprecated"), *Asset.ObjectPath.ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.PackageName:    %s"), *Asset.PackageName.ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.PackagePath:    %s"), *Asset.PackagePath.ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.AssetName:      %s"), *Asset.AssetName.ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.AssetClass:     %s  deprecated"), *Asset.AssetClass.ToString());
	UE_LOG(MyStudy, Warning, TEXT("AssetData.AssetClassPath: %s"), *Asset.AssetClassPath.ToString());
}


void UAssetRegisterFunctionLibrary::GetAssetByClass(UClass* AssetClass, TArray<FAssetData>& AssetData)
{
	FAssetRegistryModule& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistry.Get().GetAssetsByClass(AssetClass->GetClassPathName(), AssetData);
}
