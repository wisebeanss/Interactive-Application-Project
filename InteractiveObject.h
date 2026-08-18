#pragma once
#include "GameObject.h"
using namespace std;
class InteractiveObject : public GameObject
{
private:
	string name;
public:
	InteractiveObject();
	~InteractiveObject();
	string getName() const;
	virtual void use() = 0;
};

