#ifndef CARDSYSTEM_H
#define CARDSYSTEM_H

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CardSystem.generated.h"

USTRUCT(BlueprintType)
struct FCharacterCard
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Rarity; // "S", "A", "B"

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Power;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Ability;
};

UCLASS(Blueprintable)
class AETHERION_API UCardSystem : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FCharacterCard> OwnedCards;

    UFUNCTION(BlueprintCallable)
    void AddCard(const FCharacterCard& NewCard);

    UFUNCTION(BlueprintCallable)
    bool HasCard(FString CardName);
};

#endif
