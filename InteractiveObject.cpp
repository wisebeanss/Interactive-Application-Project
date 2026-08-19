#include "InteractiveObject.h"
InteractiveObject::InteractiveObject(string name, int id) : GameObject(1, 1, ' ')
{
	this->name = name;
	this->id = id;
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