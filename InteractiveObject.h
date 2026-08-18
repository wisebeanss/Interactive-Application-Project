#pragma once
#include "GameObject.h"
class InteractiveObject : public GameObject
{
public:
	InteractiveObject();
	~InteractiveObject();
	virtual void use() = 0;
};

