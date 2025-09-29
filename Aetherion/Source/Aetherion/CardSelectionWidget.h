#ifndef CARDSELECTIONWIDGET_H
#define CARDSELECTIONWIDGET_H

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardSystem.h"
#include "CardSelectionWidget.generated.h"

UCLASS()
class AETHERION_API UCardSelectionWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Characters")
    UCardSystem* CardSystem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Characters")
    bool bStarterChosen = false;

    UFUNCTION(BlueprintCallable, Category="Characters")
    void InitializeSelection(UCardSystem* InCardSystem);

    UFUNCTION(BlueprintCallable, Category="Characters")
    void ChooseStarter(const FString& StarterName, FString& OutResult);
};

#endif
