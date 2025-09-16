#include "FSM_Reasoner.h"
#include "AIActor_Guard.h"

FSM_Reasoner::~FSM_Reasoner()
{
	delete selectedOption;
	delete actorBlackboard;
	for (int i = 0; i < options.size(); i++)
	{
		delete options[i];
	}


}

bool FSM_Reasoner::Init(std::string _id, AIBrainBlackboardBase& _context) {
	actorBlackboard = &_context;
	reasonerID = _id;
	return true;
}


/*
Think is called on demand to choose from the possible Options that AI has. 

The function should implement the logic of the AI method to choose one Option as the selectedOption. 
*/
void FSM_Reasoner::Think()
{
	// note current state
	GuardState _lastState = currentState;



	
	 if (currentState == GuardState::PATROLLING)
	{
		if (actorBlackboard->GetValue("Energy") < 1)
		{
			currentState = GuardState::RESTING;
			selectedOption = GetOptionByName("OptionRest");
		}
		// TASK TODO - add in additional transitions from the Patrolling State
	}
	else if (currentState == GuardState::RESTING)
	{
		// TASK TODO - add in transitions from the Resting State

		// pseudocode

		// if energy >= 20:
		//		current state = GuardState::PATROLLING
		//		selected option = OptionPatrol

		if (actorBlackboard->GetValue("Energy") >= 20){
			currentState = GuardState::PATROLLING;
			selectedOption = GetOptionByName("OptionPatrol");
		}
	
	}
	

	


	// if state changed, call the Pre/Post Transition functions for cleanup/initialisation

	if (_lastState != currentState)
	{
		actorBlackboard->GetActorContext()->PreTransition();
	}

}




void FSM_Reasoner::SetStartingState(GuardState _state, std::string _stateName)
{
	currentState = _state;
	selectedOption = GetOptionByName(_stateName);

}




void FSM_Reasoner::SetOptions(std::vector<AIOptionBase*> _options)
{

	for (int i = 0; i < _options.size(); i++)
	{
		AIOption* o = new AIOption();
		o->Init(_options[i]->GetOptionID(), _options[i]->GetOptionAction());

		for (int j = 0; j < _options[i]->GetOptionConsiderations().size(); j++)
		{
			AIConsideration* c = new AIConsideration();
			c->Init(_options[i]->GetOptionConsiderations()[j]->GetID(), options[i]->GetOptionConsiderations()[j]->GetRule());
			o->AddOptionConsideration(c);
		}

		options.push_back(o);
	}

}

