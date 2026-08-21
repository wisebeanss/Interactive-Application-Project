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

        if (map.getObjects().empty())
        {
                map.clearObjects();
                map.setObjects(new Clocks("Clock1: The incident happened one hour after \n", 1, 4, 101));
                map.setObjects(new Clocks("Clock2: The minute hand stopped at 45.\n", 4, 4, 102));
                map.setObjects(new Clocks("Clock3: The second hand stopped at 12.\n", 1, 8, 103));
                map.setObjects(new Clocks("Clock4: This clock was 5 minutes slow.\n", 4, 8, 103));
                map.setObjects(new Mirrors("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
                map.setObjects(new Mirrors("MirrorB: You raise your\nleft hand. The reflection\nraises its right hand\n", 21, 4, 202));
                map.setObjects(new Mirrors("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
                map.setObjects(new Doors(" ", 23, 3, 301));
        }

    }
}

bool Puzzle::ROOM2(int roomID, Map& map) {
    if (roomID != 2) return false;
    if (roomID == 2)
    {
        map.clearObjects();
     /*   if (add == false)
        {
            map.clearObjects();
            map.setObjects(new PhotoFragment("Clock1: A ‘Hand’\n", 1, 4, 101));
            map.setObjects(new PhotoFragment("Clock2: A “Face”\n", 4, 4, 102));
            map.setObjects(new PhotoFragment("Clock3: “The Other person” \n", 1, 8, 103));
            map.setObjects(new Note("The Perfect poster is not first.\n", 4, 8, 103));
            map.setObjects(new Note("The Strong poster is somewhere before the Successful poster.\n", 16, 4, 201));
            map.setObjects(new Note("The Smart poster is immediately before the Perfect poster. \n", 21, 4, 202));
            map.setObjects(new Note("The Successful poster is last.\n", 21, 8, 203));
            map.setObjects(new Posters("1.THE STRONG 2.THE SMART 3.THE SUCCESSFUL 4.THE PERFECT \n", 21, 8, 203));
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
        map.clearObjects();
        if (add == false)
        {
              // map.clearObjects();
              // map.setObjects(new Phones("First call: 11:32\n", 1, 4, 101));
              // map.setObjects(new Phones("Final call: 11:37\n", 4, 4, 102));
              // map.setObjects(new Letters("I called again two minutes later. \n", 1, 8, 103));
              // map.setObjects(new Clocks("Stopped at 11:35 \n", 4, 8, 103));
              //// map.setObjects(new Suitcase("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
              // map.setObjects(new Note("You blamed yourself for what happened at 11:35,\n but you weren't there when it happened.\n", 21, 4, 202));
              // map.setObjects(new Letters("No timestamp.\n", 21, 8, 203));
              // map.setObjects(new Photograph("Taken at 10:20. \n", 21, 8, 203));
              // map.setObjects(new Watch("Stopped at 11:35. \n", 1, 8, 103));
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
        map.clearObjects();
        if (add == false)
        {
            /*   map.clearObjects();
               map.setObjects(new PhotoFragment("A photograph of you as a child.\n", 1, 4, 101));
               map.setObjects(new PhotoFragment("You and someone else are sitting together on a train.\n", 4, 4, 102));
               map.setObjects(new PhotoFragment("You and the same person are standing together.\n", 1, 8, 103));
               map.setObjects(new Posters("1.FIRST TRAIN RIDE\n 2.CHILDHOOD\n 3.LAST SUMMER\n 4.PHOTOGRAPH\n", 4, 8, 103));
               map.setObjects(new Note("Childhood came before the first train ride.\n
               The last summer was immediately before the photograph.\n
               The first train ride happened after childhood.\n
               The photograph was before my first train ride.\n
               I don't remember writing one of the lines. \n", 16, 4, 201);
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
        map.clearObjects();
        /*   map.clearObjects();
                map.setObjects(new Letters("Dear you, I wish I could tell you what happened.\n Maybe tomorrow.\n Written on Monday\n", 1, 4, 101));
                map.setObjects(new Letters("Dear you, I tried calling today.\n You didn't answer.\n I'll try again.\n Written on Wednesday \n", 4, 4, 102));
                map.setObjects(new Letters("Dear you, I don't know if you're still listening.\n I'm sorry.\n Written on Friday\n", 1, 8, 103));
                map.setObjects(new Letters("Dear you,I don't know why I keep writing these.\n You're not going to read them anyway.\n No date\n", 4, 8, 103));
                map.setObjects(new Note("The last letter was written after I stopped expecting an answer.\n", 16, 4, 201);
                map.setObjects(new Note("I stopped calling before I stopped writing.", 23, 6, 301));
                map.setObjects(new Safe(" ", 23, 6, 301));
                map.setObjects(new Lockers("The locker is empty.\n A faded sticker on the locker reads: "PROPERTY OF STAFF"\n ", 23, 6, 301));
                map.setObjects(new Lockers("Inside is an old school notebook.\nThe name has been scratched out.\n", 23, 6, 301));
                map.setObjects(new Lockers("A scarf is hanging inside.\nYou recognize it.\n You remember seeing it before.\n But you can't remember where.\n ", 23, 6, 301));
                map.setObjects(new Lockers("The locker contains a train ticket.\n Destination: UNKNOWN Seat: 18\n ", 23, 6, 301));
                map.setObjects(new Lockers("There is nothing inside.\n But someone's name is carved into the door.\n ", 23, 6, 301));
                map.setObjects(new Note("They always kept their belongings close.\n", 23, 6, 301));
                 map.setObjects(new Note(" a photograph showing the missing person wearing a scarf,\n the same scarf from Locker 3"\n, 23, 6, 301));
                  map.setObjects(new Note(" Another ticket says: "I sat opposite you." \n Your seat is 17. ", 23, 6, 301));
                   map.setObjects(new Note("I never left anything behind.\n", 23, 6, 301));
               map.setObjects(new Doors(" ", 23, 6, 301));
                add = true;*/
    }
}

bool Puzzle::ROOM6(int roomID, Map& map)
{
    if (roomID != 6) return false;
    if (roomID == 6)
    {
        map.clearObjects();
        /*   map.clearObjects();
               map.setObjects(new Drawers("A blank sheet of paper.Nothing else.\n", 1, 4, 101));
               map.setObjects(new Drawers("A train ticket.\n The destination has been scratched out.\n", 4, 4, 102));
               map.setObjects(new Drawers("A photograph.\n You recognize the person in it.\n On the back: "I'll see you again." \n", 1, 8, 103));
               map.setObjects(new Drawers("A small key.\n You don't recognize it. \n", 4, 8, 103));
               map.setObjects(new Drawers("A folded piece of paper.\n You recognize the handwriting.\n It's yours.\n", 16, 4, 201);
               map.setObjects(new Note("You searched for answers everywhere except where you left them.\n", 23, 6, 301));
               map.setObjects(new Note("The truth is not something you were given.\n", 23, 6, 301));
               map.setObjects(new Note("You already knew.\n", 23, 6, 301));
               map.setObjects(new Note("The third path is the one that stops the train.\n", 23, 6, 301));
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