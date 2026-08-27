#pragma once
template <typename T>
class Vector {
private:
	int count;
	int capacity;
	T* Array;
public:
	Vector();
	~Vector();
	T& operator[](int index);
	const T& operator[](int index) const;
	int size();
	void push_back(const T &object);
	void resize(int newCapacity);
	T* begin();
	T* end();
	void erase(int index);
	void clear();
};
template <typename T>
Vector<T>::Vector() : count(0), capacity(5), Array(new T[5]) {

}
template <typename T>
Vector<T>::~Vector() {
	delete[] Array;
}
template <typename T>
int Vector<T>::size() {
	return count;
}
template <typename T>
T& Vector<T>::operator[](int index) {
	return Array[index];
}
template <typename T>
const T& Vector<T>::operator[](int index) const {
	return Array[index];
}
template <typename T>
void Vector<T>::push_back(const T& object) {
	if (count == capacity) {
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	Array[count] = object;
	count++;
}
template <typename T>
void Vector<T>::resize(int newCapacity) {
	T* newArray = new T[newCapacity];
	for (int i = 0; i < count; i++) {
		newArray[i] = Array[i];
	}
	delete[] Array;
	Array = newArray;
	capacity = newCapacity;
}
template <typename T>
T* Vector<T>::begin() {
	return Array;
}
template <typename T>
T* Vector<T>::end() {
	return Array + count;
}
template <typename T>
void Vector<T>::erase(int index) {
	for (int i = index; i < count - 1; i++) {
		Array[i] = Array[i + 1];
	}
	count--;
}

template <typename T>
void Vector<T>::clear() {
	for (int i = 0; i < count; i++) {
		Array[i].~T(); //I didnt even know you cld do this LOL
	}
	count = 0;
}