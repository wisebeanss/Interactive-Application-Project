#include "Player.h"
Player::Player() {
	x = 0;
	y = 0;
}
Player::~Player() {

}
int Player::getX() {
	return x;
}
void Player::setX(int x) {
	this->x = x;
}
int Player::getY() {
	return y;
}
void Player::setY(int y) {
	this->y = y;
}