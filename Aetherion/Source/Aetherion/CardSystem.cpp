#include "CardSystem.h"

void UCardSystem::AddCard(const FCharacterCard& NewCard)
{
    if (!HasCard(NewCard.Name))
    {
        OwnedCards.Add(NewCard);
    }
}

bool UCardSystem::HasCard(FString CardName)
{
    for (const auto& Card : OwnedCards)
    {
        if (Card.Name == CardName)
        {
            return true;
        }
    }
    return false;
}
