#ifndef GIFTSYSTEM_H
#define GIFTSYSTEM_H

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GiftSystem.generated.h"

UCLASS(Blueprintable)
class AETHERION_API UGiftSystem : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    FString GetDailyGift(int32 Day);

    UFUNCTION(BlueprintCallable)
    FString GetFirstTimeGift();
};

#endif
