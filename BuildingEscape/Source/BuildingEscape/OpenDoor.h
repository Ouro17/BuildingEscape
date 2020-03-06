// Check MIT License for coypright issues.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor();
	void CloseDoor();

private:
	AActor* owner;

	UPROPERTY(EditAnywhere)
	float openAngle = 90.f;

	UPROPERTY(EditAnywhere)
	float doorCloseDelay = 0.5f;

	float lastDoorOpenTime;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;

	AActor* actorThatOpens;
};
