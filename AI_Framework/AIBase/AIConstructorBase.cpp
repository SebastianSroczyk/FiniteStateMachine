#include "AIConstructorBase.h"

void AIConstructorBase::DefineAI()
{
	DefineActions();
	DefineConsiderations();
	DefineOptions();
}

std::vector<AIOptionBase*> AIConstructorBase::GetOptionVector(std::vector<std::string> _selectedoptions)
{

	std::vector<AIOptionBase*> _optionVector;

	// for all options in the request list, add from the unordered map
	for (const auto& optionID : _selectedoptions)
	{
		_optionVector.push_back(options[optionID]);
	}

	return _optionVector;
}


std::vector<AIOptionBase*> AIConstructorBase::GetOptionVector()
{

	std::vector<AIOptionBase*> _optionVector;

	// for all options in the request list, add from the unordered map
	for (const auto option: options)
	{
		_optionVector.push_back(option.second);
	}

	return _optionVector;
}


