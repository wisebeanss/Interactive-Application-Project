#pragma once
#include "GameObject.h"
#include "InteractiveObject.h"
#include <conio.h>
#include <vector>

using namespace std;
class Player: public GameObject
{
private:
	vector<InteractiveObject*> Inventory;
public:
	Player();
	~Player();
	void Interact(InteractiveObject& object);
	void Equip(InteractiveObject* object);
	void Discard(InteractiveObject* object);
	void move(char movement);
};

