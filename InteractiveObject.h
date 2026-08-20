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
	bool uiActive;
protected:
	static Map& map;
public:
	InteractiveObject(string name, int id, bool isPickable);
	~InteractiveObject();
	string getName() const;
	virtual void use() = 0;
	int getId();
	bool checkIfPickable() const;
	bool getUIActive() const;
	virtual void getUIBuffer(std::string buffer[13]) const {
		for (int i = 0; i < 13; i++) buffer[i] = "                      ";
	}
	void enableUI();
};

