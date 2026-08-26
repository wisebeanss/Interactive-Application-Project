#pragma once

#include <string>
#include <vector>

using namespace std;
class Dialogue
{
private:
    int typingSpeed;

    void waitForEnter();
public:
    Dialogue();
   
    void show(const vector<string>& lines, int width = 42, int height = 10, int x = 35, int y = 15);
};