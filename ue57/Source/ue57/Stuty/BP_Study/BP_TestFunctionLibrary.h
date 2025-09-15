// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BP_TestFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE57_API UBP_TestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	static void PrintUMG_Child(FString ParentPath,FString ChildPath);
	
	
};
