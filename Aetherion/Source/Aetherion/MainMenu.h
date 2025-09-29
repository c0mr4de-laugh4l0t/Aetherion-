#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

UCLASS()
class AETHERION_API UMainMenu : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;

protected:
    UFUNCTION()
    void OnNewGameClicked();

    UFUNCTION()
    void OnLoadGameClicked();

    UFUNCTION()
    void OnShopClicked();

    UFUNCTION()
    void OnExitClicked();

private:
    UPROPERTY(meta = (BindWidget))
    class UButton* NewGameButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* LoadGameButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* ShopButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* ExitButton;
};
