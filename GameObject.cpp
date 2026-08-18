#include "GameObject.h"
GameObject::GameObject(int x, int y, char symbol) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
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
char GameObject::getSymbol() const {
	return symbol;
}
void GameObject::setSymbol(char symbol) {
	this->symbol = symbol;
}