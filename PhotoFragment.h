#pragma once
#include "InteractiveObject.h"
class PhotoFragment :
    public InteractiveObject
{
private:
    string description;
    static vector<int> Ids;
public:
    PhotoFragment(string description, int X, int Y, int id);
    ~PhotoFragment();
    void use();
};

