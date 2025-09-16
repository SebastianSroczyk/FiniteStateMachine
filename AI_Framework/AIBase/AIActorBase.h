
#ifndef AI_ACTOR_BASE_H
#define AI_ACTOR_BASE_H
#include <string>
#include "AIReasonerBase.h"
#include <AIConstructorBase.h>
class AIBrainBase;

/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once
/*
AIActorBase represents an actor or entity in the game scene that uses AI to make decisions
*/
class AIActorBase
{
public:
	virtual bool Init(std::string _id, AIConstructorBase& _constructor) = 0;

	// called each frame or decision point to make and carry out a decision
	virtual void Update(float _dt);
	virtual void PreTransition();

	void AddBBValue(std::string _key, float _value);
	void EditBBValue(std::string _key, float _newValue);
	void DeleteBBValue(std::string _key);
	float GetBBValue(std::string _key);

protected:
	std::string actorID;
	AIBrainBase* brain;
};

#endif // !AI_ACTOR_BASE_H