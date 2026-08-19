#include "Player.h"
Player::Player() : GameObject(1, 3, 'P') {
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
void Player::Interact(InteractiveObject& object) {
	object.use();
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
	if (symbol == 'e') {
		for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
			std::cout << Inventory[objIdx]->getName();
		}
		std::cout << "dadasda" << std::endl;
	}
	else if (symbol == 'f') {

	}
	else if (symbol == 'l') {
		map.nextCarriage();
		map.buildMap();
		
	}
	else {
		move(symbol, map);
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
	// Only update if valid
	if (map.validMove(newX, newY)) {
		setX(newX);
		setY(newY);
	}
}