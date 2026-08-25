#pragma once
#include "InteractiveObject.h"
#include <string>
using namespace std;
class Clocks :
    public InteractiveObject
{
private:
    string text;
    static vector<int> Ids;
public:
    Clocks(string text, int X, int Y, int id);
    ~Clocks();
    void setLine(string line);
    string centerClockText(const string& str, int width) const;
    void getUIBuffer(string buffer[13]) const;
    void use();
};

