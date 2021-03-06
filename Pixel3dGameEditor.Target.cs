// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Pixel3dGameEditorTarget : TargetRules
{
	public Pixel3dGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "GeneratedWorldGenerators" } );
		ExtraModuleNames.Add("Pixel3dGame");
	}
}
