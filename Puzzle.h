#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "Clocks.h"
#include "Mirrors.h"
#include "Doors.h"
#include "Photograph.h"
#include "Watch.h"
#include "Phones.h"
#include "Letters.h"
#include "Suitcase.h"
#include "Note.h"
#include "Lockers.h"
#include "Drawers.h"
#include "Posters.h"
#include "PhotoFragment.h"

class Puzzle :
    public InteractiveObject
{
private:

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

