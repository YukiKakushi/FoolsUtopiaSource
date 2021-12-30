// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Pixel3dGameTarget : TargetRules
{
	public Pixel3dGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "GeneratedWorldGenerators" } );
		ExtraModuleNames.Add("Pixel3dGame");

	}
}
