#include "Player.h"
Player::Player() : GameObject(3, 1, 'P') {
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
void Player::move(char movement, int boundaryX, int boundaryY)
{
	int newX = 0;
	int newY = 0;
	switch (movement) {
	case 'w':
		newX = getX() - 1;
		break;
	case 'a':
		newY = getY() - 1;
		break;
	case 's':
		newX = getX() + 1;
		break;
	case 'd':
		newY = getY() + 1;
		break;
	default:
		break;
	}
	// Only update if inside boundaries
	if (newX >= 0 && newX <= boundaryX &&
		newY >= 0 && newY <= boundaryY)
	{
		setX(newX);
		setY(newY);
	}
}