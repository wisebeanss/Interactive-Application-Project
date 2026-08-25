#pragma once
#include "InteractiveObject.h"
class Phones :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;

public:
    Phones(string text, int X, int Y, int id);
    ~Phones();
    void use();
    void getUIBuffer(string buffer[13]) const;
};

