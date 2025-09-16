
#ifndef AI_BRAIN_BB_BASE_H
#define AI_BRAIN_BB_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


class AIActorBase;

#include <map>
#include <string>

#pragma once

/*
* AIBrainBlackboardBase holds all data reqiured for the Reasoner to make a decision, including the entity this reasoner belongs to
*/
class AIBrainBlackboardBase
{
public:
	virtual bool Init(AIActorBase& _context) = 0;
	AIActorBase* GetActorContext();
	void AddNewValue(std::string name, float data);
	float GetValue(std::string name);
	int GetAndDeleteValue(std::string name);
	void EditValue(std::string name, float new_value);
	void DeleteValue(std::string name);

protected:
	std::map<std::string, float> datamap;
	AIActorBase* actorContext;
};

#endif //!AI_BRAIN_BB_BASE_H