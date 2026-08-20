#pragma once
#include "InteractiveObject.h"
class Photograph :
    public InteractiveObject
{
private:
    string description;
    static vector<int> Ids;

public:
    Photograph(string description, int id);
    ~Photograph();
    void use();
};

