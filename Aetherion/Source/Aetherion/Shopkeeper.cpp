#include "Shopkeeper.h"
#include "Blueprint/UserWidget.h"
#include "ShopUI.h"

AShopkeeper::AShopkeeper()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AShopkeeper::BeginPlay()
{
    Super::BeginPlay();

    if (ShopUIClass)
    {
        ShopUI = CreateWidget<UShopUI>(GetWorld(), ShopUIClass);
    }
}

void AShopkeeper::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AShopkeeper::OpenShop()
{
    if (ShopUI)
    {
        ShopUI->AddToViewport();
    }
}
