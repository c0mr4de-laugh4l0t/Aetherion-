#include "MainMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenu::Initialize()
{
    if (!Super::Initialize()) return false;

    if (NewGameButton)
        NewGameButton->OnClicked.AddDynamic(this, &UMainMenu::OnNewGameClicked);
    if (LoadGameButton)
        LoadGameButton->OnClicked.AddDynamic(this, &UMainMenu::OnLoadGameClicked);
    if (ShopButton)
        ShopButton->OnClicked.AddDynamic(this, &UMainMenu::OnShopClicked);
    if (ExitButton)
        ExitButton->OnClicked.AddDynamic(this, &UMainMenu::OnExitClicked);

    return true;
}

void UMainMenu::OnNewGameClicked()
{
    UGameplayStatics::OpenLevel(this, FName("MainLevel"));
}

void UMainMenu::OnLoadGameClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Load Game Clicked (hook into save system here)"));
}

void UMainMenu::OnShopClicked()
{
    UGameplayStatics::OpenLevel(this, FName("ShopLevel"));
}

void UMainMenu::OnExitClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
