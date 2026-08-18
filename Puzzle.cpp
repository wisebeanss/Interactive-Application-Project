#include "Puzzle.h"
#include <iostream>

using namespace std;

bool Puzzle::sequencePuzzle(int roomID)
{
    int answer1;
    int attempts;
    char answer2 = ' ';
    if (roomID == 1)
    {
        bool P11 = false;
        bool P12 = false;
        cout << "Clock1: The incident happened one hour after \n";
        cout << "Clock2: The minute hand stopped at 45.\n";
        cout << "Clock3:The second hand stopped at 12.\n";
        cout << "Clock4: This clock was 5 minutes slow.\n";
        cout << "Enter the time as HHMMSS (e.g., 115012): ";
        cin >> answer1;

        while (!P11) {

            if (answer1 == 115012)
            {
                cout << "\nThe clock begins ticking...\n";
                cout << "11:50...\n";
                cout << "11:51...\n";
                cout << "The time feels strangely familiar.\n";
                cout << "✓ Room 1 unlocked!\n";
                P11 = true;

                // unlock room 2
            }
            else
            {
                cout << "\nThat doesn't seem right.\n";
                P11 = false;
                if (attempts == 3) {
                    std::cout << "= !Remember the clock is 5 mins slower!=\n";
                }
            }
        }
        while (!P12) {
            if( roomID ==1 && P11)
            cout << "MirrorA: The reflection is smiling But you are not\n";
            cout << "MirrorB: You raise your left hand. The reflection raises its right hand\n";
            cout << "MirrorC:You raise your left hand.The reflection raises its left hand. You blink.  It blinks with you.\n";
       
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
        }
    }

    

    else if (roomID == 2)
    {
        // TODO: Add room 2 puzzle
        cout << "Room 2: Coming soon...\n";
    }

    else if (roomID == 3)
    {
        cout << "Enter the sequence (4 digits): ";
        cin >> answer1;

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
}