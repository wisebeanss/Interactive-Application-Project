#include "Player.h"


Player::Player() : GameObject(2, 6, 'P') {
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
void Player::Equip(InteractiveObject* object) {
	Inventory.push_back(object);
}
void Player::Discard(InteractiveObject* object) {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		if (Inventory[objIdx] == object) {
			delete Inventory[objIdx];
			Inventory.erase(Inventory.begin() + objIdx);
			break;
		}
	}
}
void Player::HandleInput(char symbol, Map &map) {
	//movement
	if (symbol == 'w' || symbol == 'a' || symbol == 's' || symbol == 'd') {
		move(symbol, map);
	}
	if (symbol == 'e') {
		for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
			std::cout << Inventory[objIdx]->getName() << " " << Inventory[objIdx]->getId();
		}
	}
	else if (symbol == 'f') {
		for (int i = 0; i < map.getObjects().size(); i++)
		{
			int objX = map.getObjects()[i]->getX();
			int objY = map.getObjects()[i]->getY();
			if ((objX == getX() && objY == getY() + 1) ||
				(objX == getX() && objY == getY() - 1) ||
				(objX == getX() + 1 && objY == getY()) ||
				(objX == getX() - 1 && objY == getY()))
			{
				cout << "\r" << string(80, ' ') << "\r";
				map.getObjects()[i]->use();
			}
		}
	}
	else if (symbol == 'l') {
		map.nextCarriage();
		map.buildMap();
	}
	else if (symbol == 'k') {
		map.nextRoom();
		map.buildMap();
	}
}
void Player::move(char movement, Map &map)
{
	int newX = getX();
	int newY = getY();
	switch (movement) {
	case 'w':
		newY -= 1;
		break;
	case 'a':
		newX -= 1;
		break;
	case 's':
		newY += 1;
		break;
	case 'd':
		newX += 1;
		break;
	default:
		break;
	}
	map.buildMap();
	// Only update if valid
	if (map.validMove(newX, newY)) {
		setX(newX);
		setY(newY);
	}
}