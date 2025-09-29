#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PurchasePromptUI.generated.h"

UCLASS()
class AETHERION_API UPurchasePromptUI : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;

    // Callback from ShopUI to actually grant coins
    UFUNCTION()
    void ConfirmPurchase();

    UFUNCTION()
    void CancelPurchase();

private:
    UPROPERTY(meta = (BindWidget))
    class UButton* YesButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* NoButton;

    UPROPERTY(EditAnywhere, Category="Shop")
    int32 CoinsToGrant = 100;

    UPROPERTY(EditAnywhere, Category="Shop")
    float PriceUSD = 0.99f;
};
