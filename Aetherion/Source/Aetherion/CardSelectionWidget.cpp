#include "CardSelectionWidget.h"

void UCardSelectionWidget::InitializeSelection(UCardSystem* InCardSystem)
{
    CardSystem = InCardSystem;
    bStarterChosen = false;
}

void UCardSelectionWidget::ChooseStarter(const FString& StarterName, FString& OutResult)
{
    if (!CardSystem)
    {
        OutResult = TEXT("No CardSystem linked!");
        return;
    }

    if (bStarterChosen)
    {
        OutResult = TEXT("You already chose your starter!");
        return;
    }

    FCharacterCard Starter;
    Starter.Name = StarterName;
    Starter.Rarity = TEXT("A");
    Starter.Power = 90;
    Starter.Ability = TEXT("Inherited Blessing");

    CardSystem->AddCard(Starter);
    bStarterChosen = true;

    OutResult = FString::Printf(TEXT("You have chosen %s as your starter character!"), *StarterName);
}
