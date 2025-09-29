#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AetherionGameModeBase.generated.h"

UCLASS()
class AETHERION_API AAetherionGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    AAetherionGameModeBase();

protected:
    virtual void BeginPlay() override;
};
