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
public:
	Player();
	~Player();
	std::string getInvItemSlot(int index) const;
	void Interact(InteractiveObject& object);
	bool Equip(InteractiveObject* object, Map &map);
	void ClearInv();
	InteractiveObject* getNearbyObject(Map &map);
	void HandleInput(char symbol, Map& map);
	void move(char movement, Map& map);
	void setInteract(bool Interact);
	bool getInteract() const;
	InteractiveObject* getInventoryItem(int index) const;
};

