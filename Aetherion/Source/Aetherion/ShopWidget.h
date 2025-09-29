#ifndef SHOPWIDGET_H
#define SHOPWIDGET_H

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopSystem.h"
#include "ShopWidget.generated.h"

UCLASS()
class AETHERION_API UShopWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    UShopSystem* ShopSystem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    FString LastMessage;

    UFUNCTION(BlueprintCallable, Category="Shop")
    void InitializeShop(UShopSystem* InShopSystem);

    UFUNCTION(BlueprintCallable, Category="Shop")
    void BuyItem(const FString& ItemName);
};

#endif
