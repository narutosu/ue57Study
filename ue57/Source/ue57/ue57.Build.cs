// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ue57 : ModuleRules
{
	public ue57(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ue57",
			"ue57/Variant_Platforming",
			"ue57/Variant_Platforming/Animation",
			"ue57/Variant_Combat",
			"ue57/Variant_Combat/AI",
			"ue57/Variant_Combat/Animation",
			"ue57/Variant_Combat/Gameplay",
			"ue57/Variant_Combat/Interfaces",
			"ue57/Variant_Combat/UI",
			"ue57/Variant_SideScrolling",
			"ue57/Variant_SideScrolling/AI",
			"ue57/Variant_SideScrolling/Gameplay",
			"ue57/Variant_SideScrolling/Interfaces",
			"ue57/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
