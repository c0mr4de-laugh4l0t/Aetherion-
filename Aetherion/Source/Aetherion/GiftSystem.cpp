#include "GiftSystem.h"

FString UGiftSystem::GetDailyGift(int32 Day)
{
    switch (Day)
    {
    case 1: return TEXT("50 Coins");
    case 2: return TEXT("100 Coins");
    case 3: return TEXT("1 Diamond");
    case 7: return TEXT("Exclusive Card Pack");
    default: return TEXT("10 Coins");
    }
}

FString UGiftSystem::GetFirstTimeGift()
{
    return TEXT("Choose any starter character card!");
}
