// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "CppBaseActor.generated.h"

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()
	// GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	UPROPERTY(VisibleAnywhere)
	FString InstanceName = "Name";

	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 0;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditInstanceOnly)
	float Amplitude = 70.0;

	UPROPERTY(EditInstanceOnly)
	float Frequency = 4.0;

	FVector InitialLocation = FVector(0.0f, 0.0f, 0.0f);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void ShowActorInformation();
};
