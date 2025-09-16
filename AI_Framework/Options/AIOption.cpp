#include "AIOption.h"

bool AIOption::Init(std::string _id, AIActionBase* _action)
{
	optionID = _id;
	optionAction = _action;

	return true;
}

