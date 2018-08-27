// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TestActor.generated.h"

UCLASS()
class T1_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
		FRotator RotationRate;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SampleMesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* collider;
		

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
		USceneComponent* SceneComponent;
	
	
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, 
			class UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, 
			const FHitResult& SweepResult);

};
