#include "Puzzle.h"
#include <iostream>


using namespace std;
int answer1;
int attempts = 0;
char answer2 = ' ';
Puzzle::Puzzle() : InteractiveObject("puzzle", 1, false)
{
    setCurrentRoom(0);
    suitcaseUnlock = false;
    spawned = false;
}
Puzzle::~Puzzle()
{

}

bool add = false;
bool Puzzle::ROOMS(int roomID, Map& map)
{
    if (roomID == 1)
    {
        if (currentRoom != 1)
        {
            spawned = false;
        }
        if (spawned == false)
        {
            setCurrentRoom(1);
            map.clearObjects();
            map.setObjects(new Clocks("\n  Clock1:\nThe incident\n happened one\n hour after 10\n", 1, 4, 101));
            map.setObjects(new Clocks("\n  Clock2:\n The minute hand\n stopped at 45.\n", 4, 4, 102));
            map.setObjects(new Clocks("\n  Clock3:\n The seconds hand\n stopped at 12 \n", 1, 8, 103));
            map.setObjects(new Clocks("\n  Clock4:\n This clock was\n 5 minutes slow.\n", 4, 8, 103));
            map.setObjects(new Mirrors("MirrorA: The reflection\nis smiling But you are not\n", 16, 4, 201));
            map.setObjects(new Mirrors("MirrorB: You raise your\nleft hand. The reflection\nraises its right hand\n", 21, 4, 202));
            map.setObjects(new Mirrors("MirrorC:You raise your\nleft hand.The reflection\nraises its left hand.\nYou blink.\nIt blinks with you.\n", 21, 8, 203));
            map.setObjects(new Doors(" ", 23, 6, 1, 1));
            map.buildMap();
            spawned = true;
        }
        return true;
    }
    if (roomID == 2)
    {
        if (currentRoom != 2)
        {
            spawned = false;
        }
        if (spawned == false)
        {
            map.clearObjects();
            map.setObjects(new PhotoFragment("PhotoFragment1:\nA 'Hand'\n", 1, 4, 101));
            map.setObjects(new PhotoFragment("PhotoFragment2:\nA \"Face\"\n", 4, 4, 102));
            map.setObjects(new PhotoFragment("PhotoFragment3:\n\"The Other person\" \n", 1, 8, 103));
            map.setObjects(new Suitcase(4, 8, 203, 2));
            map.setObjects(new Doors(" ", 23, 6, 2, 1));
            setCurrentRoom(2);
            suitcaseUnlock = false;
            spawned = true;
        }
        if (getCurrentRoom() == 2 && suitcaseUnlock == false)
        {
            for (InteractiveObject* itm : map.getObjects())
            {
                if (itm->getName() == "Suitcase")
                {
                    Suitcase* suitcase = dynamic_cast<Suitcase*>(itm);
                    if (suitcase->isUnlocked() == true)
                    {

                        suitcaseUnlock = true;
                        spawned = false;
                    }
                }
            }
        }
        if (suitcaseUnlock == true)
        {
            if (spawned == false)
            {
                map.clearObjects();
                map.setObjects(new Note("The Perfect poster\nis not first.\n", 16, 8, 200));
                map.setObjects(new Note("The Strong poster is\nsomewhere before the\nSuccessful poster.\n", 16, 4, 201));
                map.setObjects(new Note("The Smart poster is\nimmediately before the\nPerfect poster. \n", 21, 4, 202));
                map.setObjects(new Note("The Successful poster\nis last.\n", 21, 8, 203));
                map.setObjects(new Posters("1.THE STRONG\n2.THE SMART\n3.THE SUCCESSFUL\n4.THE PERFECT \n", 4, 8, 203));
                map.setObjects(new Doors(" ", 23, 6, 2, 1));
                spawned = true;
            }
        }
        return true;

    }

    if (roomID == 3)
    {
        if (currentRoom != 3)
        {
            spawned = false;
        }
        if (map.getRoom() == 1)
        {
            if (spawned == false)
            {
                map.clearObjects();
                map.setObjects(new Phones("First call:\n11:32", 2, 8, 101));
                map.setObjects(new Phones("Final call:\n11:37", 5, 4, 102));
                map.setObjects(new Letters("I called again\n two minutes later. \n", 3, 8, 103));
                map.setObjects(new Clocks("Stopped at 11:35 \n", 5, 8, 103));
                map.setObjects(new Suitcase(16, 4, 201, 3));
                map.setObjects(new Doors(" ", 23, 6, 3, 1));
                suitcaseUnlock = false;
                spawned = true;
                setCurrentRoom(3);
            }
        }
        if (getCurrentRoom() == 3 && suitcaseUnlock == false) {
            int i = 0;
            for (InteractiveObject* itm : map.getObjects())
            {
                i++;
                if (itm->getName() == "Suitcase")
                {
                    Suitcase* suitcase = dynamic_cast<Suitcase*>(itm);
                    if (suitcase->isUnlocked() == true)
                    {
                        suitcaseUnlock = true;
                        spawned = false;

                    }
                }
            }
        }
        if (suitcaseUnlock == true)
        {
            if (spawned == false)
            {
                map.clearObjects();
                map.setObjects(new Note("You blamed yourself for\nwhat happened at 11:35,\nbut you weren't there\nwhen it happened.\n", 2, 4, 202));
                map.setObjects(new Letters("No timestamp.\n", 21, 8, 203));
                map.setObjects(new Photograph("Taken at 10:20. \n", 20, 4, 203));
                map.setObjects(new Watch("Stopped at 11:35. \n", 1, 8, 103));
                map.setObjects(new Doors(" ", 23, 6, 3,1));
                spawned = true;
            }
        }
        return true;
    }
    if (roomID == 4)
    {
        if (currentRoom != 4)
        {
            spawned = false;
        }
        if (spawned == false)
        {
            map.clearObjects();
            map.setObjects(new PhotoFragment("A photograph of you\nas a child.\n", 1, 4, 101));
            map.setObjects(new PhotoFragment("You and someone else\nare sitting together\non a train. \n", 5, 4, 102));
            map.setObjects(new PhotoFragment("You and the same person\nare standing together.\n", 1, 8, 103));
            map.setObjects(new Suitcase(4, 8, 301,4));
            map.setObjects(new Doors(" ", 23, 6, 4,1));
            setCurrentRoom(4);
            suitcaseUnlock = false;
            spawned = true;
            //add = true;
        }
        if (getCurrentRoom() == 4)
        {
            int i = 0;
            for (InteractiveObject* itm : map.getObjects())
            {
                i++;
                if (itm->getName() == "Suitcase")
                {
                    Suitcase* suitcase = dynamic_cast<Suitcase*>(itm);
                    if (suitcase->isUnlocked() == true)
                    {
                        suitcaseUnlock = true;
                        spawned = false;
                    }
                }
            }
            if (suitcaseUnlock == true)
            {
                if (spawned == false)
                {
                    map.clearObjects();
                    map.setObjects(new Posters("1.FIRST TRAIN RIDE\n2.CHILDHOOD\n3.LAST SUMMER\n4. PHOTOGRAPH\n", 4, 8, 103));
                    map.setObjects(new Note("Childhood came before\nthe first train ride.\nThe last summer was\nimmediately before the\nphotograph.The first train\nride happened after\nchildhood.The photograph\nwasbefore my first train\nride.I dont remember\nwriting one of the lines. \n", 16, 4, 201));
                    map.setObjects(new Doors(" ", 23, 6, 4, 1));
                    spawned = true;
                }

            }

        }
        return true;
    }
    if (roomID == 5)
    {
        if (currentRoom != 5)
        {
            spawned = false;
        }
        if (spawned == false)
        {
            map.clearObjects();
            map.setObjects(new Letters("letter A:\nDear you, I wish I\ncould tell you\nwhat happened.\nMaybe tomorrow.\nWritten on Monday\n", 1, 4, 101));
            map.setObjects(new Letters("letter B:\nDear you, I tried\ncalling today.\nYou didn't answer.\nI'll try again.\nWritten on Wednesday \n", 4, 4, 102));
            map.setObjects(new Letters("letter C:\nDear you, I don't\nknow if you're\nstill listening.\nI'm sorry.\nWritten on Friday\n", 1, 8, 103));
            map.setObjects(new Letters("letter D:\n\"Dear you,I don't know\nwhy I keep writing\nthese.You're not going\nto read them anyway.\"\nNo date\n", 4, 8, 103));
            map.setObjects(new Note("The last letter was\nwritten after I stopped\nexpecting an answer.\n", 16, 4, 201));
            map.setObjects(new Note("I stopped calling\nbefore I stopped writing.",9, 4, 301));
            map.setObjects(new Suitcase(5, 8, 301, 5));
            map.setObjects(new Lockers("The locker is empty.\nA faded sticker reads:\n\"PROPERTY OF STAFF\"", 12, 4, 301));
            map.setObjects(new Lockers("Inside is an old\nschool notebook.The \nname has been\nscratched out.", 13, 4, 301));
            map.setObjects(new Lockers("A scarf is hanging\ninside. You recognize it.\nYou remember seeing it\nbefore. But you can't\nremember where. ", 21, 8, 301));
            map.setObjects(new Lockers("The locker contains\na train ticket.\nDestination:UNKNOWN\nSeat: 18 ", 12, 8, 301));
            map.setObjects(new Lockers("There is nothing\ninside. But someone's\nname is carved into\nthe door. ", 13, 8, 301));
            map.setObjects(new Doors(" ", 23, 6, 5, 1));
            suitcaseUnlock = false;
            spawned = true;
            setCurrentRoom(5);
        }
        if (getCurrentRoom() == 5 && suitcaseUnlock == false)
        {
            int i = 0;
            for (InteractiveObject* itm : map.getObjects())
            {
                i++;
                if (itm->getName() == "Suitcase")
                {
                    Suitcase* suitcase = dynamic_cast<Suitcase*>(itm);
                    if (suitcase->isUnlocked() == true)
                    {
                        suitcaseUnlock = true;
                        spawned = false;
                    }
                }
            }
        }
        if (suitcaseUnlock == true)
        {
            if (spawned == false)
            {
                map.clearObjects();
                map.setObjects(new Note("They always kept their belongings close.", 1, 4, 301));
                map.setObjects(new Note(" a photograph showing the missing person wearing a scarf,the same scarf from Locker 3", 1, 8, 301));
                map.setObjects(new Note(" Another ticket says: \"I sat opposite you.\" The player's seat is 17. ", 4, 4, 301));
                map.setObjects(new Note("I never left anything behind.", 4, 8, 301));
                map.setObjects(new Lockers("The locker is empty.\nA faded sticker reads:\n\"PROPERTY OF STAFF\"", 12, 4, 301));
                map.setObjects(new Lockers("Inside is an old\nschool notebook.The \nname has been\nscratched out.", 13, 4, 301));
                map.setObjects(new Lockers("A scarf is hanging\ninside. You recognize it.\nYou remember seeing it\nbefore. But you can't\nremember where. ", 21, 8, 301));
                map.setObjects(new Lockers("The locker contains\na train ticket.\nDestination:UNKNOWN\nSeat: 18 ", 12, 8, 301));
                map.setObjects(new Lockers("There is nothing\ninside. But someone's\nname is carved into\nthe door. ", 13, 8, 301));
                map.setObjects(new Doors(" ", 23, 6, 5, 1));
                spawned = true;
            }
        }
        return true;
    }
    if (roomID != 6) return false;
    if (roomID == 6)
    {
        if (currentRoom != 6)
        {
            spawned = false;
        }
        if (spawned == false)
        {
            map.clearObjects();
            map.setObjects(new Drawers("A blank sheet\nof paper.\nNothing else.\n", 1, 4, 101));
            map.setObjects(new Drawers("A train ticket.\nThe destination\nhas been scratched out.\n", 4, 4, 102));
            map.setObjects(new Drawers("A photograph.\nYou recognize\nthe person in\nit.On the back:\n\"I\'ll see\nyou again.\" \n", 1, 8, 103));
            map.setObjects(new Drawers("A small key.\nYou don't\nrecognize it. \n", 4, 8, 103));
            map.setObjects(new Drawers("A folded piece\nof paper.You\nrecognize the\nhandwriting.\nIt's yours.\n", 16, 4, 201));
            map.setObjects(new Note("You searched for\nanswers everywhere\nexcept where\nyou left them.", 16, 8, 301));
            map.setObjects(new Note("The truth is not\nsomething you\nwere given.", 20, 8, 301));
            map.setObjects(new Note("You already knew.", 20, 4, 301));
            map.setObjects(new Note("The third path is the\none that stops\nthe train.", 5, 8, 301));
            map.setObjects(new Suitcase(23, 6, 301, 6));
            map.setObjects(new Doors(" ", 23, 4, 601,61));
            map.setObjects(new Doors(" ", 23, 6, 602,62));
            map.setObjects(new Doors(" ", 23, 8, 603,63));
            suitcaseUnlock = false;
            setCurrentRoom(6);
            spawned = true;
        }
    }
    return false;
}
void Puzzle::setCurrentRoom(int room) { currentRoom = room; }
int Puzzle::getCurrentRoom() { return currentRoom; }
void Puzzle::use()
{

}   