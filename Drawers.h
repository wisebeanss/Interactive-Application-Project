#pragma once
#include "InteractiveObject.h"
class Drawers :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;
public:
    Drawers(string text, int X, int Y, int id);
    ~Drawers();

    void use();
};

