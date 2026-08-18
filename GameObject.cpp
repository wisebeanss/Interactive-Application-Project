#include "GameObject.h"
GameObject::GameObject(int x, int y) {
	this->x = x;
	this->y = y;
}
GameObject::~GameObject() {

}
int GameObject::getX() const {
	return x;
}
void GameObject::setX(int x) {
	this->x = x;
}
int GameObject::getY() const {
	return y;
}
void GameObject::setY(int y) {
	this->y = y;
}