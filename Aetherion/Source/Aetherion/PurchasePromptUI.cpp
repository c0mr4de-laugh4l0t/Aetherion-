#include "PurchasePromptUI.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UPurchasePromptUI::Initialize()
{
    if (!Super::Initialize()) return false;

    if (YesButton)
        YesButton->OnClicked.AddDynamic(this, &UPurchasePromptUI::ConfirmPurchase);
    if (NoButton)
        NoButton->OnClicked.AddDynamic(this, &UPurchasePromptUI::CancelPurchase);

    return true;
}

void UPurchasePromptUI::ConfirmPurchase()
{
    // Simulate purchase — in real release, hook to payment SDK
    UE_LOG(LogTemp, Warning, TEXT("Purchased %d coins for $%.2f"), CoinsToGrant, PriceUSD);

    // Normally we'd inform ShopUI of new balance
    // For now, we can broadcast or modify a GameInstance var
    this->RemoveFromParent();
}

void UPurchasePromptUI::CancelPurchase()
{
    UE_LOG(LogTemp, Warning, TEXT("Purchase cancelled"));
    this->RemoveFromParent();
}
