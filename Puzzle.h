#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "Clocks.h"

class Puzzle :
    public InteractiveObject
{
public:
    // Puzzle functions
    bool  ROOM1(int roomID, Map& map);
    bool  ROOM2(int roomID);
    bool  ROOM3(int roomID);
    bool  ROOM4(int roomID);
    bool  ROOM5(int roomID);
    bool  ROOM6(int roomID);
<<<<<<< HEAD

    Puzzle();

    ~Puzzle();
=======
    void use();
>>>>>>> ae32b543432de6c16533b368a0671b2dc33d5b07

   

};

