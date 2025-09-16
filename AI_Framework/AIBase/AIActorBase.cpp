#include "AIActorBase.h"
#include "AIBrainBase.h"


void AIActorBase::Update(float _dt)
{
	brain->Update();

}

void AIActorBase::PreTransition()
{

}


void AIActorBase::AddBBValue(std::string _key, float _value)
{
	brain->GetBrainBlackboard()->AddNewValue(_key, _value);

}
void AIActorBase::EditBBValue(std::string _key, float _newValue)
{
	brain->GetBrainBlackboard()->EditValue(_key, _newValue);
}
void AIActorBase::DeleteBBValue(std::string _key)
{
	brain->GetBrainBlackboard()->DeleteValue(_key);
}

float AIActorBase::GetBBValue(std::string _key)
{
	return brain->GetBrainBlackboard()->GetValue(_key);
}