// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISense.h"
#include "MyAIController.generated.h"

class  UBehaviorTree;
class UAIPerceptionComponent;


UCLASS()
class MYPROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:

	

	AMyAIController();

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* BTAI;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = " AI")
	UAIPerceptionComponent* PerComp;

	/*UFUNCTION()*/
	//void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);


	virtual void Tick(float DeltaTime) override;

};

