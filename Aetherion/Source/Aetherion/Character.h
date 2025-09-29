#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character.generated.h"

UCLASS()
class AETHERION_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyCharacter();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void StartJump();
    void StopJump();
};
