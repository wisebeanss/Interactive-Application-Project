#include "InteractiveObject.h"
#include "Map.h"
Map& InteractiveObject::map = getGameMap();
InteractiveObject::InteractiveObject(string name, int id, bool isPickable) : GameObject(1, 1, ' ')
{
	this->name = name;
	this->id = id;
	this->isPickable = isPickable;
	uiActive = false;
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
bool InteractiveObject::getUIActive() const {
	return uiActive;
}
void InteractiveObject::enableUI() {
	uiActive = true;
}
void InteractiveObject::disableUI() {
	uiActive = false;
}

