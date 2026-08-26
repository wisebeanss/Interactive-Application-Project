#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "MapObjects.h"
#include "Player.h"
class Puzzle :
    public InteractiveObject
{
private:
    int currentRoom;
    bool suitcaseUnlock;
    bool spawned;
public:
    // Puzzle functions
    bool ROOMS(int roomID, Map& map, Player& player);
    void setCurrentRoom(int room);
    int getCurrentRoom();


    Puzzle();

    ~Puzzle();

    void use();


   

};

