#pragma once
#include "InteractiveObject.h"
class Note : public InteractiveObject {
private:
	string text;
public:
	void use();
};