#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"


ATower::ATower()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	TankRef = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();
	}
}

bool ATower::InFireRange() const
{
	if (TankRef)
	{
		return  FVector::Dist(this->GetActorLocation(), TankRef->GetActorLocation()) <= FireRate ;
	}
	return false;
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TankRef)
	{
		float Distance = FVector::Dist(GetActorLocation(), TankRef->GetActorLocation());
		if (Distance <= FireRange)
		{
			RotateTurret(TankRef->GetActorLocation());
		}
	}
}

