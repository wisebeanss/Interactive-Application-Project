#pragma once
#include "InteractiveObject.h"
#include <string>
#include "Timer.h"
#include "Map.h"
class Doors : public InteractiveObject
{
private:
    string line;
    int roomID = 0;
    int question = 0;
    bool unlocked;
    Timer timer;

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
