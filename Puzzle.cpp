#include "Puzzle.h"
#include <iostream>

using namespace std;
void Puzzle::sequencePuzzle(int roomID)
{
    int answer;

    if (roomID == 1)
    {
        
        cout << "Enter the time as HHMMSS: ";
        cin >> answer;

        if (answer == 115012)
        {
            cout << "\nThe clock begins ticking...\n";
            cout << "11:50...\n";
            cout << "11:51...\n";
            cout << "The time feels strangely familiar.\n";

            // unlock room 2
        }
        else
        {
            cout << "\nThat doesn't seem right.\n";
        }
    }

    else if (roomID == 3)
    {

        cout << "Enter the sequence: ";
        cin >> answer;

        if (answer == 1234)
        {
            cout << "\nYou remember the order now.\n";
            cout << "But you still don't remember why.\n";

            // unlock second puzzle in room 3
        }
        else
        {
            cout << "\nThe memories don't fit together.\n";
        }
    }
}

void Puzzle::room1()
{
    sequencePuzzle(1);
    identifyObjectPuzzle(1);
}

void Puzzle::room2()
{
    fragmentPuzzle(2);
    orderingPuzzle(2);
}

void Puzzle::room3()
{
    sequencePuzzle(3);
    identifyObjectPuzzle(3);
}

void Puzzle::room4()
{
    fragmentPuzzle(4);
    orderingPuzzle(4);
}

void Puzzle::room5()
{
    deductionPuzzle(5);
    choicePuzzle(5);
}

void Puzzle::room6()
{
    deductionPuzzle(6);
    choicePuzzle(6);
}