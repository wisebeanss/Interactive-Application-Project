#pragma once
#include "InteractiveObject.h"
class Keys :
    public InteractiveObject
{
private:
	static vector<int> Ids;
public:
	Keys(string text, int id);
	~Keys();
	void use();
};

