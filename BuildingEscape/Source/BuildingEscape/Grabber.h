// © Mario Arnold 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach in cm
		float Reach = 100.0f;
		UPhysicsHandleComponent* PhysicsHandle = nullptr;
		UInputComponent* InputComponent = nullptr;
		// Ray-cast and grab what is reached
		void Grab();

		// Called when grab is released
		void Release();

		// Find (assumed) attached physics handle component
		void FindPhysicsHandleComponent();

		// Setup (assumed) attached input compoinet
		void SetupInputComponent();

		// Return hit for first physics body in reach
		const FHitResult GetFirstPhysicsBodyInReach();

		// Returns current start of reach line
		FVector GetReachLineStart();

		// Returns current end of reach line
		FVector GetReachLineEnd();
};     

