
#include "FingRandomPointTask.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UFingRandomPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
	if (!BBComp)return EBTNodeResult::Failed;

	UNavigationSystemV1 *NavSys = UNavigationSystemV1::GetCurrent(OwnerComp.GetWorld());

	FVector Origin = OwnerComp.GetOwner()->GetActorLocation();
	FVector NewLocation;
	
	bool bFound = NavSys->K2_GetRandomReachablePointInRadius(OwnerComp.GetWorld(), Origin, NewLocation, 1500.0f);

	if (!bFound) return EBTNodeResult::Failed;

	BBComp->SetValueAsVector("PatrolPoint", NewLocation);

	return EBTNodeResult::Succeeded;
}
