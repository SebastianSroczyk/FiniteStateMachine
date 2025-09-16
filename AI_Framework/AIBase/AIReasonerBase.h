#ifndef AI_REASONER_BASE_H
#define AI_REASONER_BASE_H

/*
CMP304/MAT501 AI Framework (2025)
*/


#include "AIBrainBlackboardBase.h"
#include <vector>
#include "AIOptionBase.h"
#include <string>

#pragma once

/**
* AIReasonerBase is responsible for selecting one of the possible options that the Actor will perform.
*/
class AIReasonerBase
{
public:
	virtual bool Init(std::string _id, AIBrainBlackboardBase& _context) = 0;
	virtual void SetOptions(std::vector<AIOptionBase*> _options) = 0;
	void ClearOptions();
	AIOptionBase* GetOptionByName(std::string _name);
	AIOptionBase* GetSelectedOption();

	ActionStatus Update();
	virtual void Reset();
protected:
	void Sense();
	virtual void Think() = 0;
	virtual ActionStatus Act();
	

	AIBrainBlackboardBase* actorBlackboard; // brain's blackboard for the reasoner's context, e.g. Actor's Brain
	std::vector<AIOptionBase*> options; // vector of all possible Options the reasoner can select from
	AIOptionBase* selectedOption; // the selected option - set by Update()

	std::string reasonerID;
};

#endif // !AI_REASONER_BASE_H