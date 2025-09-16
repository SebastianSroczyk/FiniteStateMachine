#include "AIBrain_FSM.h"


#include "AIBrainBlackboard.h"
#include "FSM_Reasoner.h"

bool AIBrain_FSM::Init(AIConstructorBase& _constructor, AIActorBase& _actorContext)
{

	brainBlackboard = new AIBrainBlackboard();
	brainBlackboard->Init(_actorContext);



	brainReasoner = new FSM_Reasoner();

	brainReasoner->SetOptions(_constructor.GetOptionVector());

	FSM_Reasoner* _reasoner = static_cast<FSM_Reasoner*>(brainReasoner);
	_reasoner->SetStartingState(FSM_Reasoner::GuardState::RESTING, "OptionRest");


	_reasoner->Init("FMS Reasoner", *brainBlackboard);
	return true;
}

void AIBrain_FSM::Update()
{
	// call the reasoner
	brainReasoner->Update();

}
