#pragma once
#include "InteractiveObject.h"
class Posters :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Posters(string text, int id);
	~Posters();
	void use();
};

