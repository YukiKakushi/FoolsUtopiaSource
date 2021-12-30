// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Pixel3dGame : ModuleRules
{
	public Pixel3dGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" , "Paper2D" });
	}
}
