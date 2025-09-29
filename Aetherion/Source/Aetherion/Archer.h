#pragma once

#include "CoreMinimal.h"
#include "Character.h"
#include "Archer.generated.h"

UCLASS()
class AETHERION_API AArcher : public AMyCharacter
{
    GENERATED_BODY()

public:
    AArcher();

protected:
    void ShootArrow();
};
