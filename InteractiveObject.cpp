#include "InteractiveObject.h"
InteractiveObject::InteractiveObject() : GameObject(1, 1, ' ') {

}
InteractiveObject::~InteractiveObject() {

}
string InteractiveObject::getName() const {
	return name;
}