#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shopkeeper.generated.h"

UCLASS()
class AETHERION_API AShopkeeper : public AActor
{
    GENERATED_BODY()

public:
    AShopkeeper();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category="Shop")
    void OpenShop();

private:
    UPROPERTY(EditAnywhere, Category="Shop")
    TSubclassOf<class UUserWidget> ShopUIClass;

    UPROPERTY()
    class UShopUI* ShopUI;
};
