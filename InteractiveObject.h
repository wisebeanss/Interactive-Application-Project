#pragma once
#include "GameObject.h"
#include "Map.h"
using namespace std;
class InteractiveObject : public GameObject
{
private:
	string name;
	int id;
	bool isPickable;
protected:
	static Map& map;
public:
	InteractiveObject(string name, int id, bool isPickable);
	~InteractiveObject();
	string getName() const;
	virtual void use() = 0;
	int getId();
	bool checkIfPickable() const;
	
};

