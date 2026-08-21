#pragma once
#include "InteractiveObject.h"
#include<string>
using namespace std;
class Doors :
    public InteractiveObject
{
    private:
        string line;
        int roomID = 0;
        int question = 0;
        int attempts = 0;
        bool unlocked;
    public:
         Doors(string lines, int X, int Y, int id);
        ~Doors();
        bool isUnlocked() const;
        void changeUnlockedState(bool state);
        void setLine(string line);
        void use();
        void setRoomID(bool id);
};

