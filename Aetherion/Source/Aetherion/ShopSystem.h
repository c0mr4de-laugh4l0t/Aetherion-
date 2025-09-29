#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CardSystem.h"
#include "ShopSystem.generated.h"

USTRUCT(BlueprintType)
struct FShopItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CoinCost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DiamondCost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsCardPack; // true = random pack, false = specific card
};

UCLASS(Blueprintable)
class AETHERION_API UShopSystem : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PlayerCoins;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PlayerDiamonds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FShopItem> ShopInventory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCardSystem* CardSystem;

    UFUNCTION(BlueprintCallable)
    bool PurchaseItem(const FString& ItemName, FString& OutResult);

private:
    bool CanAfford(const FShopItem& Item) const;
    void GrantCardReward(const FShopItem& Item, FString& OutResult);
};

#endif
