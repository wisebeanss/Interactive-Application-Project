#pragma once
#include "InteractiveObject.h"
class Vector {
private:
	int length;
	int capacity;
	InteractiveObject** Array;
public:
	Vector();
	~Vector();
	InteractiveObject*& at(int index);
	int size();
	void push_back(InteractiveObject*&object);
	void resize(int newCapacity);
	InteractiveObject** begin();
	InteractiveObject** end();
	void erase(int index);
	void clear();
};

