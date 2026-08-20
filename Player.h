#pragma once
#include "GameObject.h"
#include "InteractiveObject.h"
#include "Map.h"
using namespace std;
class Player: public GameObject
{
private:
	vector<InteractiveObject*> Inventory;
	bool interact;
public:
	Player();
	~Player();
	void Interact(InteractiveObject& object);
	void Equip(InteractiveObject* object);
	void Discard(InteractiveObject* object);
	InteractiveObject* getNearbyObject(Map &map);
	void HandleInput(char symbol, Map& map);
	void move(char movement, Map& map);
	void setInteract(bool Interact);
	bool getInteract();
};

