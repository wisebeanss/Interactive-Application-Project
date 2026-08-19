#pragma once
#include "InteractiveObject.h"
class Note : public InteractiveObject {
private:
	string text;
	static vector<int> Ids;
public:
	Note(string text , int id, bool isPickable);
	~Note();
	void use();
};