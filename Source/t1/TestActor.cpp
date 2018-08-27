// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
	
	SampleMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("SAMPLE TEXT"));
	SampleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	
	RotationRate = FRotator(0.0f, 180.0f, 0.0f);

	collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Ze collider"));
	collider->SetGenerateOverlapEvents(true);
	collider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	collider->OnComponentBeginOverlap.AddDynamic(this, &ATestActor::OnOverlapBegin);
	collider->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(RotationRate * DeltaTime);

}

void ATestActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor, UPrimitiveComponent * OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{	
	if (OtherActor == nullptr || OtherComp == nullptr || OtherActor == this)
		return;
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, (TEXT("KADING")));
	Destroy();
}

