#pragma once

#include "CoreMinimal.h"
#include "Character.h"
#include "Warrior.generated.h"

UCLASS()
class AETHERION_API AWarrior : public AMyCharacter
{
    GENERATED_BODY()

public:
    AWarrior();

protected:
    void HeavyAttack();
};
