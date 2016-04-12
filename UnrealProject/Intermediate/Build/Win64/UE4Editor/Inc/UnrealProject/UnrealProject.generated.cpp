// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UnrealProject.h"
#include "UnrealProject.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealProject() {}
	void UBubblesGenerator::StaticRegisterNativesUBubblesGenerator()
	{
	}
	IMPLEMENT_CLASS(UBubblesGenerator, 1305709825);
	void UCityMap::StaticRegisterNativesUCityMap()
	{
	}
	IMPLEMENT_CLASS(UCityMap, 33312026);
	void AUnrealProjectGameMode::StaticRegisterNativesAUnrealProjectGameMode()
	{
	}
	IMPLEMENT_CLASS(AUnrealProjectGameMode, 3408781336);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API class UClass* Z_Construct_UClass_USceneComponent();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();

	UNREALPROJECT_API class UClass* Z_Construct_UClass_UBubblesGenerator_NoRegister();
	UNREALPROJECT_API class UClass* Z_Construct_UClass_UBubblesGenerator();
	UNREALPROJECT_API class UClass* Z_Construct_UClass_UCityMap_NoRegister();
	UNREALPROJECT_API class UClass* Z_Construct_UClass_UCityMap();
	UNREALPROJECT_API class UClass* Z_Construct_UClass_AUnrealProjectGameMode_NoRegister();
	UNREALPROJECT_API class UClass* Z_Construct_UClass_AUnrealProjectGameMode();
	UNREALPROJECT_API class UPackage* Z_Construct_UPackage__Script_UnrealProject();
	UClass* Z_Construct_UClass_UBubblesGenerator_NoRegister()
	{
		return UBubblesGenerator::StaticClass();
	}
	UClass* Z_Construct_UClass_UBubblesGenerator()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_UnrealProject();
			OuterClass = UBubblesGenerator::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Column = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Column"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(CPP_PROPERTY_BASE(Column, UBubblesGenerator), 0x0010000000000005);
				UProperty* NewProp_Row = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Row"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(CPP_PROPERTY_BASE(Row, UBubblesGenerator), 0x0010000000000005);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("ComponentReplication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BubblesGenerator.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BubblesGenerator.h"));
				MetaData->SetValue(OuterClass, TEXT("OnlyDefaultConstructorDeclared"), TEXT(""));
				MetaData->SetValue(NewProp_Column, TEXT("Category"), TEXT("Generation"));
				MetaData->SetValue(NewProp_Column, TEXT("ModuleRelativePath"), TEXT("BubblesGenerator.h"));
				MetaData->SetValue(NewProp_Row, TEXT("Category"), TEXT("Generation"));
				MetaData->SetValue(NewProp_Row, TEXT("ModuleRelativePath"), TEXT("BubblesGenerator.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBubblesGenerator(Z_Construct_UClass_UBubblesGenerator, &UBubblesGenerator::StaticClass, TEXT("UBubblesGenerator"), false, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBubblesGenerator);
	UClass* Z_Construct_UClass_UCityMap_NoRegister()
	{
		return UCityMap::StaticClass();
	}
	UClass* Z_Construct_UClass_UCityMap()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_USceneComponent();
			Z_Construct_UPackage__Script_UnrealProject();
			OuterClass = UCityMap::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Speed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Speed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Speed, UCityMap), 0x0010000000000005);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Left, UCityMap, bool);
				UProperty* NewProp_Left = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Left"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Left, UCityMap), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(Left, UCityMap), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Right, UCityMap, bool);
				UProperty* NewProp_Right = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Right"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Right, UCityMap), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(Right, UCityMap), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Down, UCityMap, bool);
				UProperty* NewProp_Down = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Down"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Down, UCityMap), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(Down, UCityMap), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Up, UCityMap, bool);
				UProperty* NewProp_Up = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Up"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Up, UCityMap), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(Up, UCityMap), sizeof(bool), true);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Trigger PhysicsVolume ComponentReplication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("CityMap.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
				MetaData->SetValue(OuterClass, TEXT("OnlyDefaultConstructorDeclared"), TEXT(""));
				MetaData->SetValue(NewProp_Speed, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_Speed, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
				MetaData->SetValue(NewProp_Left, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_Left, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
				MetaData->SetValue(NewProp_Right, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_Right, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
				MetaData->SetValue(NewProp_Down, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_Down, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
				MetaData->SetValue(NewProp_Up, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_Up, TEXT("ModuleRelativePath"), TEXT("CityMap.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCityMap(Z_Construct_UClass_UCityMap, &UCityMap::StaticClass, TEXT("UCityMap"), false, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCityMap);
	UClass* Z_Construct_UClass_AUnrealProjectGameMode_NoRegister()
	{
		return AUnrealProjectGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AUnrealProjectGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage__Script_UnrealProject();
			OuterClass = AUnrealProjectGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UnrealProjectGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UnrealProjectGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUnrealProjectGameMode(Z_Construct_UClass_AUnrealProjectGameMode, &AUnrealProjectGameMode::StaticClass, TEXT("AUnrealProjectGameMode"), false, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealProjectGameMode);
	UPackage* Z_Construct_UPackage__Script_UnrealProject()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/UnrealProject")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x78B2DD04;
			Guid.B = 0x159F9535;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
