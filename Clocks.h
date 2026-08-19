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
    Clocks(string lines, int X, int Y);
    ~Clocks();
    void setLine(string line);
    void use();
};

