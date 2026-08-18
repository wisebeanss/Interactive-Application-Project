#pragma once
#include "GameObject.h"
#include "InteractiveObject.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include "Map.h"

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
	void HandleInput(char symbol, Map& map);
	void move(char movement, Map& map);
};

