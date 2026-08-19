#include "Puzzle.h"
#include <iostream>


using namespace std;
int answer1;
int attempts = 0;
char answer2 = ' ';


Puzzle::~Puzzle()
{

}


bool add = false;

bool Puzzle::ROOM1(int roomID, Map &map)
{
    if (roomID != 1) return false;
    
    if (roomID == 1)
    {
        //bool P11 = false;
        //bool P12 = false;

        if (add == false)
        {
            map.setObjects(new Clocks("Clock1: The incident happened one hour after \n", 1, 1, 1));
            map.setObjects(new Clocks("Clock2: The minute hand stopped at 45.\n", 4, 1, 1));
            map.setObjects(new Clocks("Clock3:The second hand stopped at 12.\n", 1, 5, 1));
            map.setObjects(new Clocks("Clock4: This clock was 5 minutes slow.\n", 4, 5, 1));
            add = true;
        }


        //cout << "Clock1: The incident happened one hour after \n";
        //cout << "Clock2: The minute hand stopped at 45.\n";
        //cout << "Clock3:The second hand stopped at 12.\n";
        //cout << "Clock4: This clock was 5 minutes slow.\n";
        //cout << "Enter the time as HHMMSS (e.g., 115012): ";
        //cin >> answer1;

        //while (!P11) {

        //    if (answer1 == 115012)
        //    {
        //        cout << "\nThe clock begins ticking...\n";
        //        cout << "11:50...\n";
        //        cout << "11:51...\n";
        //        cout << "The time feels strangely familiar.\n";
        //        cout << "✓ Room 1 unlocked!\n";
        //        P11 = true;

        //        // unlock room 2
        //    }
        //    else
        //    {
        //        cout << "\nThat doesn't seem right.\n";
        //        P11 = false;
        //        if (attempts == 3) {
        //            std::cout << "= !Remember the clock is 5 mins slower!=\n";
        //        }
        //    }
        //}
  /*      while (!P12) {
            if (roomID == 1 && P11)
                cout << "MirrorA: The reflection is smiling But you are not\n";
                cout << "MirrorB: You raise your left hand. The reflection raises its right hand\n";
                cout << "MirrorC:You raise your left hand.The reflection raises its left hand. You blink.  It blinks with you.\n";
                cin >> answer2;

            if (answer2 == 'C') {
                cout << "---\n";
                cout << "Mirror C ripples softly.\n";
                cout << "'I show only what is real.'\n";
                cout << "The true mirror sees you exactly as you are.\n";
                cout << "Lock clicks open.\n";
          
                P12 = true;
            }
            else {
                cout << "---\n";
                cout << "The mirror distorts. It is lying.\n";
                cout << "Think again.\n\n";
            }
        }*/
    }
}
    ///
    bool Puzzle::ROOM2(int roomID){
        if (roomID != 2) return false;
        if (roomID == 2)
        {
            bool P21 = false;
            bool P22 = false;
         
            while (!P21) {


                //3 photo 
                std::cout << "Photo1\n";
                std::cout << "Photo2\n";
                std::cout << "photo3\n";
                //after player collect all photo 
                int total = 0;

                /* add the total
                for (int p; p < 4; p++) {
                    if (p == true) {
                        total++;
                    }
                }*/


                if (total == 3) {

                    cout << "You have collected all Photo Fragments!";
                    cout << "The suitcase is now open!";
                    bool P21 = true;
                }
                else {

                    cout << " You haven't collected all Photo Fragments!";

                }

            }
            
            while (!P22) {
                if (roomID == 2 && P21) {

                    if (answer1 == 1243) {

                        cout << "Layer upon layer of masks, hiding who you truly are at the very end. ";
                        cout << "Words fade into view beneath the last portrait: ";
                        cout << "After all this time… are you tired? ";
                        cout << "The door opens.";
                        P22 = true;
                    }
                    else {
                        cout << "Are you sure you arranged it in the right order?";
                        cout << "Try again.";
                        P22 = false;
                    }

                }
            }
        }
    }

    bool Puzzle::ROOM3(int roomID)
    {

        if (roomID != 3)return false;
        if (roomID == 3)
        {
            cout << "Enter the sequence (4 digits): ";
            cin >> answer1;
        }

        if (answer1 == 1234)
        {
            cout << "\nYou remember the order now.\n";
            cout << "But you still don't remember why.\n";
            cout << "✓ First puzzle in Room 3 unlocked!\n";

            // unlock second puzzle in room 3
        }
        else
        {
            cout << "\nThe memories don't fit together.\n";
        }
    }


    bool Puzzle::ROOM4(int roomID)
    {
        if (roomID != 4) return false;
        if (roomID == 4)
        {
            bool P41 = false;
            bool P42 = false;

            while (!P41) {


                //3 photo 
                std::cout << "Photo1\n";
                std::cout << "Photo2\n";
                std::cout << "photo3\n";

                //after player collect all photo 
                int total = 0;

                /* add the total
                for (int p; p < 4; p++) {
                    if (p == true) {
                        total++;
                    }
                }*/


                if (total == 3) {

                    cout << "You have collected all Photo Fragments!";
                    cout << "The suitcase is now open!";
                    bool P21 = true;
                }
                else {

                    cout << " You haven't collected all Photo Fragments!";
                    bool P21 = false;
                }

            }

            while (!P42) {
                if (roomID == 4 && P41) {

                    if (answer1 == 2143) {

                        cout << "You remember the beginning.";
                        cout << "Now remember the end.";
                        cout << "The door opens.";
                        P42 = true;
                    }
                    else {
                        cout << "Are you sure you arranged it in the right order?";
                        cout << "Try again.";
                        P42 = false;
                    }

                }
            }
        }
    }


    bool Puzzle::ROOM5(int roomID)
    {
        if (roomID != 5) return false;
        if (roomID == 5)
        {
            bool P51 = false;
            bool P52 = false;

            while (!P51) {

                if (answer2 == 'D') {

                    cout << "The safe is now open!";
                    P51 = true;
                }

                else {
                    cout << "Try again.";
                    P51 = false;
                }

            }

            while (!P52) {

                if (answer1 == 3) {

                    cout << "The door clicks open.";
                    P51 = true;
                }

                else {
                    cout << "Try again.";
                    P51 = false;
                }



            }
        }
    }

    bool Puzzle::ROOM6(int roomID)
    {
        if (roomID != 6) return false;
        if (roomID == 6)
        {
            bool P61 = false;
            bool P62 = false;

            while (!P61) {

                if (answer1 == 3) {

                    cout << "The door clicks open.";
                    P61 = true;
                }

                else {
                    cout << "Try again.";
                    P61 = false;
                }
            }

            while (!P62) {

                int door = 0;
                switch (door) {
                case 1:
                    cout << "Try again.";
                    P62 = false;
                    break;

                case 2:
                    cout << "Try again.";
                    P62 = false;
                    break;

                case 3:
                    cout << "Try again.";
                    P62 = false;
                    break;

                case 4:
                    cout << "Try again.";
                    P62 = false;
                    break;

                case 5:
                    cout << "escaped";
                    P62 = true;
                    break;



                }




            }


        }

    void Puzzle::use()
    {


    }