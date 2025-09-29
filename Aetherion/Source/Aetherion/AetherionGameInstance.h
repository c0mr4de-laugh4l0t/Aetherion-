#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AetherionGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FShopItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    int32 CoinCost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    int32 DiamondCost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    bool bIsCharacter;
};

UCLASS()
class AETHERION_API UAetherionGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UAetherionGameInstance();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Economy")
    int32 Coins;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Economy")
    int32 Diamonds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Economy")
    TArray<FString> OwnedCharacters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shop")
    TArray<FShopItem> ShopItems;

    UFUNCTION(BlueprintCallable, Category="Economy")
    bool PurchaseItem(const FShopItem& Item, bool& bSuccess, FString& OutMessage);
};
