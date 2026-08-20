#pragma once
#include "InteractiveObject.h"
class Watch :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;

public:
    Watch(string text, int X, int Y, int id);
    ~Watch();
    void use();
    string centerWatchText(const string &str, int width) const;
};

