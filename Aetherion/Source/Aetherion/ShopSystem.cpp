#include "ShopSystem.h"

bool UShopSystem::PurchaseItem(const FString& ItemName, FString& OutResult)
{
    for (FShopItem& Item : ShopInventory)
    {
        if (Item.ItemName == ItemName)
        {
            if (CanAfford(Item))
            {
                if (Item.CoinCost > 0 && PlayerCoins >= Item.CoinCost)
                {
                    PlayerCoins -= Item.CoinCost;
                }
                else if (Item.DiamondCost > 0 && PlayerDiamonds >= Item.DiamondCost)
                {
                    PlayerDiamonds -= Item.DiamondCost;
                }
                else
                {
                    OutResult = TEXT("Not enough coins or diamonds!");
                    return false;
                }

                GrantCardReward(Item, OutResult);
                return true;
            }
            else
            {
                OutResult = FString::Printf(TEXT("Not enough currency! Would you like to buy %s for $0.99 (local equivalent)?"), *ItemName);
                return false;
            }
        }
    }

    OutResult = TEXT("Item not found in shop.");
    return false;
}

bool UShopSystem::CanAfford(const FShopItem& Item) const
{
    return (PlayerCoins >= Item.CoinCost) || (PlayerDiamonds >= Item.DiamondCost);
}

void UShopSystem::GrantCardReward(const FShopItem& Item, FString& OutResult)
{
    if (!CardSystem)
    {
        OutResult = TEXT("Shop has no linked CardSystem!");
        return;
    }

    if (Item.bIsCardPack)
    {
        // Example random pack logic
        FCharacterCard Reward;
        Reward.Name = TEXT("Random Demigod");
        Reward.Rarity = TEXT("S");
        Reward.Power = 120;
        Reward.Ability = TEXT("Blessing of Zeus");
        CardSystem->AddCard(Reward);
        OutResult = FString::Printf(TEXT("You received a random pack reward: %s!"), *Reward.Name);
    }
    else
    {
        // Direct character purchase
        FCharacterCard Reward;
        Reward.Name = Item.ItemName;
        Reward.Rarity = TEXT("A");
        Reward.Power = 100;
        Reward.Ability = TEXT("Inherited blessing");
        CardSystem->AddCard(Reward);
        OutResult = FString::Printf(TEXT("You purchased %s as a character card!"), *Reward.Name);
    }
}
