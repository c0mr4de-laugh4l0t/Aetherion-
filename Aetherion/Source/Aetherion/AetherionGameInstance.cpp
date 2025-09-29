#include "AetherionGameInstance.h"
#include "Kismet/GameplayStatics.h"

UAetherionGameInstance::UAetherionGameInstance()
{
    Coins = 100;
    Diamonds = 10;

    // Example shop setup
    FShopItem Warrior;
    Warrior.ItemName = "Warrior Character";
    Warrior.CoinCost = 200;
    Warrior.DiamondCost = 0;
    Warrior.bIsCharacter = true;
    ShopItems.Add(Warrior);

    FShopItem Mage;
    Mage.ItemName = "Mage Character";
    Mage.CoinCost = 0;
    Mage.DiamondCost = 5;
    Mage.bIsCharacter = true;
    ShopItems.Add(Mage);

    FShopItem DiamondPack;
    DiamondPack.ItemName = "50 Diamonds Pack";
    DiamondPack.CoinCost = 0;
    DiamondPack.DiamondCost = 0; // real money
    DiamondPack.bIsCharacter = false;
    ShopItems.Add(DiamondPack);
}

bool UAetherionGameInstance::PurchaseItem(const FShopItem& Item, bool& bSuccess, FString& OutMessage)
{
    bSuccess = false;

    if (Item.CoinCost > 0 && Coins >= Item.CoinCost)
    {
        Coins -= Item.CoinCost;
        if (Item.bIsCharacter)
        {
            OwnedCharacters.Add(Item.ItemName);
        }
        bSuccess = true;
        OutMessage = FString::Printf(TEXT("Purchased %s for %d coins"), *Item.ItemName, Item.CoinCost);
    }
    else if (Item.DiamondCost > 0 && Diamonds >= Item.DiamondCost)
    {
        Diamonds -= Item.DiamondCost;
        if (Item.bIsCharacter)
        {
            OwnedCharacters.Add(Item.ItemName);
        }
        bSuccess = true;
        OutMessage = FString::Printf(TEXT("Purchased %s for %d diamonds"), *Item.ItemName, Item.DiamondCost);
    }
    else if (Item.DiamondCost == 0 && Item.CoinCost == 0)
    {
        OutMessage = TEXT("This requires real money purchase!");
    }
    else
    {
        OutMessage = TEXT("Not enough funds!");
    }

    return bSuccess;
}
