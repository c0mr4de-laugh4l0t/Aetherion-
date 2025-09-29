using UnrealBuildTool;

public class Aetherion : ModuleRules
{
    public Aetherion(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "UMG"   // ✅ for UI widgets
            }
        );

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
