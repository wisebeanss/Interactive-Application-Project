#pragma once
#include "InteractiveObject.h"
class Letters :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Letters(string text, int X, int Y, int id);
	~Letters();
	void getUIBuffer(string buffer[13]) const;
	void use();
};

