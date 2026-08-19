#pragma once
#include "GameObject.h"
using namespace std;
class InteractiveObject : public GameObject
{
private:
	string name;
	int id;
	bool isPickable;
public:
	InteractiveObject(string name, int id, bool isPickable);
	~InteractiveObject();
	string getName() const;
	virtual void use() = 0;
	int getId();
	bool checkIfPickable() const;
	
};

