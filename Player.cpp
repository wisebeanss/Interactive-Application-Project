#include "Player.h"
Player::Player() : GameObject(0, 0, 'P') {
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
void Player::move(char movement)
{
	switch (movement) {
	case 'W':
		setX(getX() + 1);
		break;
	case 'A':
		setY(getY() - 1);
		break;
	case 'S':
		setX(getX() - 1);
		break;
	case 'D':
		setY(getY() + 1);
		break;
	default:
		break;
	}
}