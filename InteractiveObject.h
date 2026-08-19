#pragma once
#include "GameObject.h"
using namespace std;
class InteractiveObject : public GameObject
{
private:
	string name;
protected:
	int id;
public:
	InteractiveObject(string name, int id);
	~InteractiveObject();
	string getName() const;
	virtual void use() = 0;
};

