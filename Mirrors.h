#pragma once
#include "InteractiveObject.h"
class Mirrors :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Mirrors(string text, int X, int Y, int id);
	~Mirrors();
	void use();
	void getUIBuffer(string buffer[13]) const override;
	string centerMirrorText(string str, int width) const;
};

