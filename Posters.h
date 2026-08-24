#pragma once
#include "InteractiveObject.h"
class Posters :
    public InteractiveObject
{
private:
	string text;
	static vector<int> Ids;
public:
	Posters(string text, int X, int Y, int id);
	~Posters();
	void use();
	void getUIBuffer(string buffer[13]) const override;
	string centerPosterText(string str, int width) const;
};

