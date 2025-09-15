// Fill out your copyright notice in the Description page of Project Settings.


#include "Stuty/BP_Study/BP_TestFunctionLibrary.h"
#include "ue57.h"


void UBP_TestFunctionLibrary::PrintUMG_Child(FString ParentPath,FString ChildPath)
{
	UObject* ChildPB = LoadObject<UObject>(nullptr,ChildPath);
	UE_LOG(MyStudy, Warning, TEXT("AssetPath %s"), *ChildPath);
	if(UBlueprint* BpObj = Cast<UBlueprint>(ChildPB))
	{
		if (auto BpParent = BpObj->ParentClass)
		{
			FString ObjName = BpParent->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("ParentName ============= %s"), *ObjName);
		}

		if (auto BpSuper = BpObj->GetClass()->GetSuperClass())
		{
			FString ObjName = BpSuper->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("SuperClassName ========= %s"), *ObjName);
		}
	}

	if(UBlueprint* BpObj = Cast<UBlueprint>(ChildPB))
	{
		//蓝图的ParentClass
		if (auto BpParent = BpObj->ParentClass)
		{
			FString ObjName = BpParent->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("ParentName %s"), *ObjName);
		}
		//蓝图的GeneratedClass
		if (auto BpGen = BpObj->GeneratedClass)
		{
			FString ObjName = BpGen->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("GenClassName %s"), *ObjName);
			//蓝图的GeneratedClass的父类
			FString GenSuperClassName = BpGen->GetSuperClass()->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("GenSuperClassName %s"), *GenSuperClassName);
		}

		if (auto BpGenNative = GetParentNativeClass(BpObj->GeneratedClass))
		{
			FString ObjName = BpGenNative->GetFName().ToString();
			UE_LOG(MyStudy, Warning, TEXT("ParentGenNativeName %s"), *ObjName);

			bool b1 = BpObj->GeneratedClass->IsNative();
			bool b2 = BpGenNative->IsNative();
			UE_LOG(MyStudy, Warning, TEXT("GeneratedClass = %d, BpGenNative = %d"), b1, b2);
		}
	}

	FString ChildPath_C = ChildPath.Replace(TEXT("UMG_Child'"), TEXT("UMG_Child_C'"));
	FString ParentPath_C = ParentPath.Replace(TEXT("UMG_Parent'"), TEXT("UMG_Parent_C'"));
	UObject* ChildObj = LoadObject<UObject>(nullptr,ChildPath_C);
	UObject* ParentObj = LoadObject<UObject>(nullptr,ParentPath_C);
	if (ChildObj && ParentObj)
	{
		FString ChildObjName = ChildObj->GetFName().ToString();
		UE_LOG(MyStudy, Warning, TEXT("ChildObjName ================= %s"), *ChildObjName);
		FString ParentObjName = ParentObj->GetFName().ToString();
		UE_LOG(MyStudy, Warning, TEXT("ParentObjName ================ %s"), *ParentObjName);
	}

	//加载UMG蓝图和普通蓝图
	UClass * ChildC = ChildObj->GetClass();
	UClass * ParentC = ParentObj->GetClass();
	if (ChildC && ParentC)
    {
        FString ChildCName = ChildC->GetFName().ToString();
        UE_LOG(MyStudy, Warning, TEXT("ChildCName ================= %s"), *ChildCName);
        FString ParentCName = ParentC->GetFName().ToString();
        UE_LOG(MyStudy, Warning, TEXT("ParentCName ================ %s"), *ParentCName);
    }

	
	UE_LOG(MyStudy, Warning, TEXT("蓝图资产ChildBP ==================== %s"), *ChildPB->GetName());
	UE_LOG(MyStudy, Warning, TEXT("ChildBP.GetClass ================= %s"), *ChildPB->GetClass()->GetName());
	UE_LOG(MyStudy, Warning, TEXT("ChildBP.GetSuperClass.GetClass() = %s"), *ChildPB->GetClass()->GetSuperClass()->GetName());

	UE_LOG(MyStudy, Warning, TEXT("类资产 ChildBP_C ================== %s"), *ChildObj->GetName());
	UE_LOG(MyStudy, Warning, TEXT("ChildBP_C.GetClass =============== %s"), *ChildObj->GetClass()->GetName());
	UE_LOG(MyStudy, Warning, TEXT("ChildBP_C.GetSuperClass.GetClass = %s"), *ChildObj->GetClass()->GetSuperClass()->GetName());
}
