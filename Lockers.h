#pragma once
#include "InteractiveObject.h"
class Lockers :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;

public:
    Lockers(string text, int X, int Y, int id);
    ~Lockers();
    void getUIBuffer(string buffer[13]) const;
    void use();
};

