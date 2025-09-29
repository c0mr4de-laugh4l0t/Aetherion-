#include "Warrior.h"
#include "GameFramework/Actor.h"

AWarrior::AWarrior()
{
    // Warrior-specific setup (e.g., high health)
}

void AWarrior::HeavyAttack()
{
    UE_LOG(LogTemp, Warning, TEXT("Warrior performs a heavy attack!"));
}
