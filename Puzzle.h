#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "MapObjects.h"
class Puzzle :
    public InteractiveObject
{
private:
    int currentRoom;
    bool suitcaseUnlock;
public:
    // Puzzle functions
    bool ROOMS(int roomID, Map& map);
    void setCurrentRoom(int room);
    int getCurrentRoom();


    Puzzle();

    ~Puzzle();

    void use();


   

};

