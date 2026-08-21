#pragma once
#include "InteractiveObject.h"
#include <string>
#include "map.h"
#include "Clocks.h"
#include "Mirrors.h"
#include "Doors.h"
#include "PhotoFragment.h"
#include "Note.h"
#include "Posters.h"
#include "Letters.h"
#include "Phones.h"
#include "Photograph.h"
#include "Watch.h"
#include "Suitcase.h"
class Puzzle :
    public InteractiveObject
{
private:
    int currentRoom;
public:
    // Puzzle functions
    bool  ROOMS(int roomID, Map& map);
    //bool  ROOM2(int roomID, Map& map);
    //bool  ROOM3(int roomID, Map& map);
    //bool  ROOM4(int roomID, Map& map);
    //bool  ROOM5(int roomID, Map& map);
    //bool  ROOM6(int roomID, Map& map);
    void setCurrentRoom(int room);
    int getCurrentRoom();


    Puzzle();

    ~Puzzle();

    void use();


   

};

