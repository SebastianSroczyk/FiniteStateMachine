#include "AIReasonerBase.h"

void AIReasonerBase::ClearOptions()
{
	options.clear();
}


AIOptionBase* AIReasonerBase::GetSelectedOption()
{
	return selectedOption;
}

ActionStatus AIReasonerBase::Update()
{
	Sense();
	Think();
	return Act();

}

void AIReasonerBase::Sense()
{

}


ActionStatus AIReasonerBase::Act()
{
	return selectedOption->GetOptionAction()->PerformAction(*actorBlackboard);

}


void AIReasonerBase::Reset()
{

}

AIOptionBase* AIReasonerBase::GetOptionByName(std::string _name)
{
	for (auto const option : options)
	{
		if (option->GetOptionID() == _name)
		{
			return option;
		}
	}

	return nullptr;

}