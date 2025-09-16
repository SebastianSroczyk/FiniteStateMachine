
#ifndef AI_CONSTRUCTOR_BASE_H
#define AI_CONSTRUCTOR_BASE_H


/*
CMP304/MAT501 AI Framework (2025)
*/


#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include "AIOptionBase.h"
#include "AIConsiderationBase.h"
#include "AIActionBase.h"


/*
AIConstructorBase contains the data used to define how an UI shoudl operate, through createion of Options, Considerations and Actions
*/
class AIConstructorBase
{
public:
	virtual bool Init() = 0;
	virtual void DefineActions() = 0;
	virtual void DefineConsiderations() = 0;
	virtual void DefineOptions() = 0;

	void DefineAI();
	std::vector<AIOptionBase*> GetOptionVector(std::vector<std::string> _selectedoptions);
	std::vector<AIOptionBase*> GetOptionVector();

	std::unordered_map<std::string, AIActionBase*> actions;
	std::unordered_map<std::string, AIConsiderationBase*> considerations;
	std::unordered_map<std::string, AIOptionBase*> options;

};

#endif // !AI_CONSTRUCTOR_BASE_H