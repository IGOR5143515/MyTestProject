// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Sight.h"
#include "MyProject/MyProjectCharacter.h"


AMyAIController::AMyAIController()
{
	PerComp = CreateDefaultSubobject<UAIPerceptionComponent>("PerComp");
	/*PerComp->OnTargetPerceptionUpdated.AddDynamic(this, &AMyAIController::OnTargetDetected);*/
    SetPerceptionComponent(*PerComp);
   
  
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	RunBehaviorTree(BTAI);
	
}

//void AMyAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
//{
//
//    
//
//    //if (Stimulus.WasSuccessfullySensed())
//    //{
//    //    
//    //    BBC->SetValueAsObject("EnemyActor", Actor);
//    //    UE_LOG(LogTemp, Warning, TEXT("Set EnemyActor: %s"), *Actor->GetName());
//    //}
//    //else
//    //    BBC->SetValueAsObject("EnemyActor", nullptr);
//
//}

void AMyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UBlackboardComponent* BBC = GetBlackboardComponent();
    if (!BBC || !PerComp) return;

    TArray<AActor*>Arr;

    PerComp->GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), Arr);

    if (Arr.Num() == 0) {
        BBC->SetValueAsObject("EnemyActor", nullptr);
        return;
    }

    for (AActor* Act : Arr)
    {
        if (Act && Act->IsA(ACharacter::StaticClass())) // Проверяем, что это персонаж
        {
            BBC->SetValueAsObject("EnemyActor", Act);
            return; // Останавливаемся, как только нашли подходящего врага
        }
    }
    

    BBC->SetValueAsObject("EnemyActor", nullptr);



}

