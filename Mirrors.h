#pragma once
#include "InteractiveObject.h"
class Mirrors :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Mirrors(string text, int id, bool isPickable);
	~Mirrors();
	void use();
};

