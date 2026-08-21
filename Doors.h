#pragma once
#include "InteractiveObject.h"
#include <string>
class Doors : public InteractiveObject
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
    int getRoomID() const;
    bool isUnlocked() const;
    void changeUnlockedState(bool state);
    void setLine(string line);
    void use();
    void setRoomID(int id);
};
