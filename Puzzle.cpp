#include "Puzzle.h"
#include <iostream>


using namespace std;
int answer1;
int attempts = 0;
char answer2 = ' ';
Puzzle::Puzzle() : InteractiveObject("puzzle", 1, false)
{
    
}
Puzzle::~Puzzle()
{

}

bool add = false;
bool Puzzle::ROOM1(int roomID, Map& map)
{
    if (roomID != 1) return false;

    if (roomID == 1)
    {
        //bool P11 = false;
        //bool P12 = false;

        if (add == false)
        {
                map.clearObjects();
                map.setObjects(new Clocks("Clock1: The incident happened one hour after \n", 1, 4, 101));
                map.setObjects(new Clocks("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
                map.setObjects(new Clocks("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
                map.setObjects(new Clocks("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
                map.setObjects(new Mirrors("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
                map.setObjects(new Mirrors("MirrorB: You raise your\nleft hand. The reflection\nraises its right hand\n", 21, 4, 202));
                map.setObjects(new Mirrors("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
                map.setObjects(new Doors(" ", 23, 6, 301));
                add = true;
        }

    }
}

bool Puzzle::ROOM2(int roomID, Map& map) {
    if (roomID != 2) return false;
    if (roomID == 2)
    {
     /*   if (add == false)
        {
            map.clearObjects();
            map.setObjects(new PhotoFragment("Clock1: The incident happened one hour after \n", 1, 4, 101));
            map.setObjects(new PhotoFragment("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
            map.setObjects(new PhotoFragment("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
            map.setObjects(new Note("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
            map.setObjects(new Note("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
            map.setObjects(new Note("MirrorB: You raise your\nleft hand. The reflection\nraises its right hand\n", 21, 4, 202));
            map.setObjects(new Note("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
            map.setObjects(new Posters("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
            map.setObjects(new Doors(" ", 23, 6, 301));
            add = true;
        }*/

        
    }
}
bool Puzzle::ROOM3(int roomID, Map& map)
{

    if (roomID != 3)return false;
    if (roomID == 3)
    {
        if (add == false)
        {
              // map.clearObjects();
              // map.setObjects(new Phones("Clock1: The incident happened one hour after \n", 1, 4, 101));
              // map.setObjects(new Phones("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
              // map.setObjects(new Letters("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
              // map.setObjects(new Clocks("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
              //// map.setObjects(new Suitcase("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
              // map.setObjects(new Note("MirrorB: You raise your\nleft hand. The reflection\nraises its right hand\n", 21, 4, 202));
              // map.setObjects(new Letters("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
              // map.setObjects(new Photograph("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
              // map.setObjects(new Watch("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
              // map.setObjects(new Doors(" ", 23, 6, 301));
              // add = true;
        }
    }
}


bool Puzzle::ROOM4(int roomID, Map& map)
{
    if (roomID != 4) return false;
    if (roomID == 4)
    {
        if (add == false)
        {
            /*   map.clearObjects();
               map.setObjects(new PhotoFragment("Clock1: The incident happened one hour after \n", 1, 4, 101));
               map.setObjects(new PhotoFragment("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
               map.setObjects(new PhotoFragment("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
               map.setObjects(new Posters("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
               map.setObjects(new Note("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201);
              map.setObjects(new Suitcase(" ", 23, 6, 301));
              map.setObjects(new Doors(" ", 23, 6, 301));
               add = true;*/
        }
    }
}
bool Puzzle::ROOM5(int roomID, Map& map)
{
    if (roomID != 5) return false;
    if (roomID == 5)
    {
        /*   map.clearObjects();
                map.setObjects(new Letters("Clock1: The incident happened one hour after \n", 1, 4, 101));
                map.setObjects(new Letters("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
                map.setObjects(new Letters("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
                map.setObjects(new Letters("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
                map.setObjects(new Note("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201);
                map.setObjects(new Note(" ", 23, 6, 301));
                map.setObjects(new Safe(" ", 23, 6, 301));
                map.setObjects(new Lockers(" ", 23, 6, 301));
                map.setObjects(new Lockers(" ", 23, 6, 301));
                map.setObjects(new Lockers(" ", 23, 6, 301));
                map.setObjects(new Lockers(" ", 23, 6, 301));
                map.setObjects(new Lockers(" ", 23, 6, 301));
                map.setObjects(new Note(" ", 23, 6, 301));
                 map.setObjects(new Note(" ", 23, 6, 301));
                  map.setObjects(new Note(" ", 23, 6, 301));
                   map.setObjects(new Note(" ", 23, 6, 301));
               map.setObjects(new Doors(" ", 23, 6, 301));
                add = true;*/
    }
}

bool Puzzle::ROOM6(int roomID, Map& map)
{
    if (roomID != 6) return false;
    if (roomID == 6)
    {
        /*   map.clearObjects();
               map.setObjects(new Drawers("Clock1: The incident happened one hour after \n", 1, 4, 101));
               map.setObjects(new Drawers("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
               map.setObjects(new Drawers("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
               map.setObjects(new Drawers("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
               map.setObjects(new Drawers("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201);
               map.setObjects(new Note(" ", 23, 6, 301));
               map.setObjects(new Note(" ", 23, 6, 301));
               map.setObjects(new Note(" ", 23, 6, 301));
               map.setObjects(new Note(" ", 23, 6, 301));
               map.setObjects(new Suitcase(" ", 23, 6, 301));
               map.setObjects(new Doors(" ", 23, 6, 301));
               map.setObjects(new Doors(" ", 23, 6, 301));
              map.setObjects(new Doors(" ", 23, 6, 301));
               add = true;*/

    }
}
void Puzzle::use()
{

}