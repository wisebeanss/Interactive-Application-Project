#pragma once
#include "GameObject.h"
#include "InteractiveObject.h"
#include "Map.h"
#include <array>
using namespace std;
class Player: public GameObject
{
private:
	array<InteractiveObject*, 7> Inventory;
	bool interact;
	Map &map;
	Timer timer;
public:
	Player();
	Player(Map &map);
	~Player();
	std::string getInvItemName(int index) const;
	void Interact(InteractiveObject& object);
	bool Equip(InteractiveObject* object);
	void ClearInv();
	InteractiveObject* getNearbyObject();
	void HandleInput(char symbol);
	void move(char movement);
	void setInteract(bool Interact);
	bool getInteract() const;
	bool hasItem(string name) const;
	InteractiveObject* getInventoryItem(int index) const;
};

