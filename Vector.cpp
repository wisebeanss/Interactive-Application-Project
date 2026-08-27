#include "Vector.h"
Vector::Vector() : length(0), capacity(5), Array(new InteractiveObject* [5]) {

}

Vector::~Vector() {
	delete[] Array;
}
InteractiveObject*& Vector::at(int index) {
	if (index > length) {
		index = length;
	}
	return Array[index];
}
int Vector::size() {
	return length;
}


void Vector::push_back(InteractiveObject*& object) {
	if (length == capacity) {
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	Array[length] = object;
	length++;
}

void Vector::resize(int newCapacity) {
	InteractiveObject** newArray = new InteractiveObject * [newCapacity];
	int elementsToCopy = (length < newCapacity) ? length : newCapacity;
	for (int i = 0; i < elementsToCopy; i++) {
		newArray[i] = Array[i];
	}
	delete[] Array;
	Array = newArray;
	capacity = newCapacity;
}
InteractiveObject** Vector::begin() {
	return Array;
}

InteractiveObject** Vector::end() {
	return Array + length;
}
void Vector::erase(int index) {
	for (int i = index; i < length - 1; i++) {
		Array[i] = Array[i + 1];
	}
	length--;
}

void Vector::clear() {
	length = 0;
}