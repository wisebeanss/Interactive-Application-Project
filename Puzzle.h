#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "MapObjects.h"
class Puzzle
{
private:
    int currentRoom;
public:
    // Puzzle functions
    void Carriages(int carriageID, int roomID, Map& map);
    void setCurrentCarriage(int carriage);
    int getCurrentCarriage();
    void setCurrentRoom(int room);
    int getCurrentRoom();

    Puzzle();

    ~Puzzle();

    void use();


   

};

