#include "InteractiveObject.h"
InteractiveObject::InteractiveObject(string name, int id, bool isPickable) : GameObject(1, 1, ' ')
{
	this->name = name;
	this->id = id;
	this->isPickable = isPickable;
}
InteractiveObject::~InteractiveObject() {

}
string InteractiveObject::getName() const {
	return name;
}
int InteractiveObject::getId()
{
	return id;
}
bool InteractiveObject::checkIfPickable() const {
	return isPickable;
}