#pragma once

#include "CoreMinimal.h"
#include "Character.h"
#include "Mage.generated.h"

UCLASS()
class AETHERION_API AMage : public AMyCharacter
{
    GENERATED_BODY()

public:
    AMage();

protected:
    void CastSpell();
};
