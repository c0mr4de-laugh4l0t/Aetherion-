#include "AetherionGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.h"

AAetherionGameModeBase::AAetherionGameModeBase()
{
    DefaultPawnClass = nullptr; // No player pawn in main menu
}

void AAetherionGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    if (UClass* MenuClass = LoadClass<UMainMenu>(nullptr, TEXT("/Game/UI/MainMenu.MainMenu_C")))
    {
        UMainMenu* Menu = CreateWidget<UMainMenu>(GetWorld(), MenuClass);
        if (Menu)
        {
            Menu->AddToViewport();
        }
    }
}
