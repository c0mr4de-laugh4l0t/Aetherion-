#include "Mage.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

AMage::AMage()
{
    // Mage-specific setup (e.g., mana pool)
}

void AMage::CastSpell()
{
    UE_LOG(LogTemp, Warning, TEXT("Mage casts a spell!"));
}
