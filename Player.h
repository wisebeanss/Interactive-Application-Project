#pragma once
#include "InteractiveObject.h"
#include <vector>
using namespace std;
class Player
{
private:
	int x;
	int y;
	vector<InteractiveObject*> Inventory;
public:
	Player();
	~Player();
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y) ;
	void Interact(InteractiveObject& object);
	void Equip(InteractiveObject* object);
	void Discard(InteractiveObject* object);
	void move(char movement);
};

