#pragma once
#include "GameObject.h"
#include "InteractiveObject.h"
#include <conio.h>
#include <iostream>
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
	void HandleInput(char symbol);
	void move(char movement, int boundaryX, int boundaryY);
};

