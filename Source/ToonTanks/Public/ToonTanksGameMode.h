#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

class AToonTanksPlayerController;
class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:
	UPROPERTY()
	TObjectPtr<ATank> Tank;

	UPROPERTY()
	TObjectPtr<AToonTanksPlayerController> ToonTanksPlayerController;

	float StartDelay = 3.f;
	void HandleGameStart();

	int32 GetTargetTowerCount();
};
