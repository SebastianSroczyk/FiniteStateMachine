#include "AIBrainBlackboardBase.h"

void AIBrainBlackboardBase::AddNewValue(std::string name, float data)
{
	datamap[name] = data;
}

float AIBrainBlackboardBase::GetValue(std::string name)
{
	return datamap[name];
}

int AIBrainBlackboardBase::GetAndDeleteValue(std::string name)
{
	int returnValue = datamap[name];
	datamap.erase(name);
	return returnValue;
}

void AIBrainBlackboardBase::DeleteValue(std::string name)
{

	datamap.erase(name);

}

void AIBrainBlackboardBase::EditValue(std::string name, float new_value)
{
	datamap.erase(name);
	datamap[name] = new_value;
}


AIActorBase* AIBrainBlackboardBase::GetActorContext()
{
	return actorContext;
}
