#include "ShopUI.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "AetherionGameInstance.h"

bool UShopUI::Initialize()
{
    if (!Super::Initialize()) return false;

    if (BuyButton)
        BuyButton->OnClicked.AddDynamic(this, &UShopUI::OnBuyClicked);
    if (SellButton)
        SellButton->OnClicked.AddDynamic(this, &UShopUI::OnSellClicked);
    if (ExitButton)
        ExitButton->OnClicked.AddDynamic(this, &UShopUI::OnExitClicked);

    return true;
}

void UShopUI::OnBuyClicked()
{
    UAetherionGameInstance* GI = Cast<UAetherionGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (GI && GI->ShopItems.Num() > 0)
    {
        FShopItem ItemToBuy = GI->ShopItems[0]; // Example: first item
        bool bSuccess;
        FString Result;
        GI->PurchaseItem(ItemToBuy, bSuccess, Result);
        UE_LOG(LogTemp, Warning, TEXT("%s"), *Result);
    }
}

void UShopUI::OnSellClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Selling not yet implemented with GameInstance"));
}

void UShopUI::OnExitClicked()
{
    this->RemoveFromParent();
}
