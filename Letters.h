#pragma once
#include "InteractiveObject.h"
class Letters :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Letters(string text, int id, bool isPickable);
	~Letters();
	void use();
};

