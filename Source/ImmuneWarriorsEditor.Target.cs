// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ImmuneWarriorsEditorTarget : TargetRules
{
	public ImmuneWarriorsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("ImmuneWarriors");

		//bCompileChaos = true;
		//bUseChaos = true;
	}
}
