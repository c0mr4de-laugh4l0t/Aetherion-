#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopUI.generated.h"

UCLASS()
class AETHERION_API UShopUI : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;

protected:
    UFUNCTION()
    void OnBuyClicked();

    UFUNCTION()
    void OnSellClicked();

    UFUNCTION()
    void OnExitClicked();

private:
    UPROPERTY(meta = (BindWidget))
    class UButton* BuyButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* SellButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* ExitButton;

    UPROPERTY(EditAnywhere, Category="Shop")
    int32 PlayerCoins = 100;

    UPROPERTY(EditAnywhere, Category="Shop")
    int32 ItemCost = 20;
};
