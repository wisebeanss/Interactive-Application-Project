#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "Clocks.h"
#include "Mirrors.h"

class Puzzle :
    public InteractiveObject
{
public:
    // Puzzle functions
    bool  ROOM1(int roomID, Map& map);
    bool  ROOM2(int roomID, Map& map);
    bool  ROOM3(int roomID, Map& map);
    bool  ROOM4(int roomID, Map& map);
    bool  ROOM5(int roomID, Map& map);
    bool  ROOM6(int roomID, Map& map);


    Puzzle();

    ~Puzzle();

    void use();


   

};

