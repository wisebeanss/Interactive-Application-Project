#include "Vector.h"
Vector::Vector() : count(0), capacity(5), Array(new InteractiveObject* [5]) {

}

Vector::~Vector() {
	delete[] Array;
}

int Vector::size() {
	return count;
}

InteractiveObject*& Vector::operator[](int index) {
	return Array[index];
}

InteractiveObject* const& Vector::operator[](int index) const {
	return Array[index];
}

void Vector::push_back(InteractiveObject*& object) {
	if (count == capacity) {
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	Array[count] = object;
	count++;
}

void Vector::resize(int newCapacity) {
	InteractiveObject** newArray = new InteractiveObject * [newCapacity];
	int elementsToCopy = (count < newCapacity) ? count : newCapacity;
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
	return Array + count;
}
void Vector::erase(int index) {
	for (int i = index; i < count - 1; i++) {
		Array[i] = Array[i + 1];
	}
	count--;
}

void Vector::clear() {
	count = 0;
}