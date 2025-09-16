#include "AIConstructor_FSM_Stealth.h"
#include <iostream>
#include "AIActor_Guard.h"
#include "FSM_Reasoner.h"


bool AIConstructor_FSM_Stealth::Init() {


	return true;
}

/*
DefineActions creates all the possible actions that the AI can perform
*/
void AIConstructor_FSM_Stealth::DefineActions()
{
	
	// ** Rest Action **
	
	//Define the function for Resting
	auto restFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Guard* actor = static_cast<AIActor_Guard*>(bb.GetActorContext());
		
		// Call behaviour functions here
		actor->Rest();

		
		return ActionStatus::ACTION_SUCCESS;
		};


	// Link the function to an identifier
	AddActionByName("ActionRest", restFunction);



	// ** Patrol Action **

	//Define the function for Patrolling
	auto patrolFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Guard* actor = static_cast<AIActor_Guard*>(bb.GetActorContext());

		// Call behaviour functions here
		actor->Patrol();

		return ActionStatus::ACTION_SUCCESS;

		};


	// Link the function to an identifier
	AddActionByName("ActionPatrol", patrolFunction);


	//	**	Chase Action	**

	// Define the function for chase
	auto chaseFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Guard* actor = static_cast<AIActor_Guard*>(bb.GetActorContext());

		// Call behaviour function here
		actor->Chase();

		return ActionStatus::ACTION_SUCCESS;

		};

	AddActionByName("ActionChase", chaseFunction);

	//	**	Investigate Action ** 
	
	//Define Investigation action
	auto investigateFunction = [](AIBrainBlackboardBase& bb) -> ActionStatus {
		AIActor_Guard* actor = static_cast<AIActor_Guard*>(bb.GetActorContext());

		// Call behaviour function here
		actor->Investigate();

		return ActionStatus::ACTION_SUCCESS;
		};

	AddActionByName("ActionInvestigate", investigateFunction);
}


void AIConstructor_FSM_Stealth::DefineConsiderations()
{

}



/*
* DefineOptions links the Options with Considerations and Actions
*/
void AIConstructor_FSM_Stealth::DefineOptions()
{


	AddOptionByName("OptionRest", "ActionRest");
	AddOptionByName("OptionPatrol", "ActionPatrol");

	// TASK TODO - add code to initialise new options, linking an action


}


																
void AIConstructor_FSM_Stealth::AddActionByName(std::string _actionName, std::function<ActionStatus(AIBrainBlackboardBase&)> _function)
{

	//Define an action, and init with the function which will be called when the action is selected
	AIAction* _action = new AIAction();
	_action->Init(_actionName, _function);
	actions.insert({ _actionName, _action });
}

void AIConstructor_FSM_Stealth::AddOptionByName(std::string _optionName, std::string _actionName)
{
	// create an option for action
	AIOption* _option = new AIOption();
	_option->Init(_optionName, actions[_actionName]);
	options.insert({ _optionName, _option });
}