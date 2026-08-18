#include "Player.h"
Player::Player() {
	x = 0;
	y = 0;
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
int Player::getX() const{
	return x;
}
void Player::setX(int x) {
	this->x = x;
}
int Player::getY() const{
	return y;
}
void Player::setY(int y) {
	this->y = y;
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