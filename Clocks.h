#pragma once
#include "InteractiveObject.h"
#include <string>
using namespace std;
class Clocks :
    public InteractiveObject
{
private:
    string line;
public:
    Clocks(string lines, int X, int Y, int id);
    ~Clocks();
    void setLine(string line);
    void use();
};

