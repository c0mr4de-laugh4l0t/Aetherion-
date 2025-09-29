#include "ShopWidget.h"

void UShopWidget::InitializeShop(UShopSystem* InShopSystem)
{
    ShopSystem = InShopSystem;
    LastMessage = TEXT("Welcome to the Shop!");
}

void UShopWidget::BuyItem(const FString& ItemName)
{
    if (!ShopSystem) return;

    FString Result;
    bool Success = ShopSystem->PurchaseItem(ItemName, Result);
    LastMessage = Result;

    if (!Success)
    {
        // In a real game, trigger payment flow here
        UE_LOG(LogTemp, Warning, TEXT("Real money purchase prompt: %s"), *Result);
    }
}
