#include "InteractiveObject.h"
InteractiveObject::InteractiveObject(string name, int id) : GameObject(1, 1, ' ') {
	this->id = id;
}
InteractiveObject::~InteractiveObject() {

}
string InteractiveObject::getName() const {
	return name;
}