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
    Clocks(string lines);
    ~Clocks();
    void setLine(string line);
    void use();
};

