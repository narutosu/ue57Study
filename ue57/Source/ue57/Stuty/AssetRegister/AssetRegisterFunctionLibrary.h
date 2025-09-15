// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetRegisterFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE57_API UAssetRegisterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Utilities")
	static void PrintObjectAssetAllName(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "Utilities")
	static void PrintAssetAllName(FSoftObjectPath SoftPath);
	
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	static void GetAssetByClass(UClass* AssetClass, TArray<FAssetData>& AssetData);
};
