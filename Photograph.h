#pragma once
#include "InteractiveObject.h"
class Photograph :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;

public:
    Photograph(string text, int X, int Y, int id);
    ~Photograph();
    void getUIBuffer(string buffer[13]) const;
    void use();
};

