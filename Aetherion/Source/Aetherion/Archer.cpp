#include "Archer.h"
#include "GameFramework/Actor.h"

AArcher::AArcher()
{
    // Archer-specific setup (e.g., ranged attack speed)
}

void AArcher::ShootArrow()
{
    UE_LOG(LogTemp, Warning, TEXT("Archer shoots an arrow!"));
}
