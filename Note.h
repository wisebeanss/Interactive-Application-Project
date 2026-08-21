#pragma once
#include "InteractiveObject.h"
class Note : public InteractiveObject 
{
private:
	string text;
	static vector<int> Ids;
public:
	Note(string text, int X, int Y, int id);
	~Note();
	void use();
};