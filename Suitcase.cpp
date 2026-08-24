#include "Suitcase.h"
#include <iostream>
#include <string>
using namespace std;

Suitcase::Suitcase(int x, int y, int id, int room)
    : InteractiveObject("Suitcase", id, false),
    roomID(room),
    unlocked(false),
    noOfPhotos(0),
    puzzleSolved(false),
    progressState(0)
{
    setX(x);
    setY(y);
    setSymbol(']');
}

bool Suitcase::isUnlocked()
{
    return unlocked;
}

void Suitcase::collectPhoto()
{
    if (roomID == 1)
    {
        noOfPhotos = noOfPhotos + 1;
    }
}

bool Suitcase::hasAllPhotos()
{
    if (roomID == 1)
    {
        return noOfPhotos == 3;
    }
    return false;
}

void Suitcase::markPuzzleSolved()
{
    if (roomID == 2)
    {
        puzzleSolved = true;
    }
}

void Suitcase::setProgressState(int s)
{
    if (roomID == 3)
    {
        progressState = s;
    }
}

bool Suitcase::tryUnlock()
{
    bool canUnlock = false;
    string hintMsg;

    if (roomID == 1)
    {
        canUnlock = hasAllPhotos();
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        if (canUnlock)
        {
            cout << "\r" << string(80, ' ') << "\r";
            cout << "A hand reaching out.\n";
            cout << "A face turned away.\n";
            cout << "Someone sitting beside you.\n";
            cout << "You stare at the completed image.\n";
            cout << "Was I really there?\n";
            unlocked = true;
            cout << "\nA note has appeared nearby.\n";
            return true;
        }
        else
        {
            cout << "\n" << hintMsg << "\n";
            return false;
        }
    }
    else if (roomID == 2)
    {
        canUnlock = puzzleSolved;
        hintMsg = "The suitcase is still locked. Solve the puzzle first.";
    }
    else if (roomID == 3)
    {
        canUnlock = (progressState >= 2);
        hintMsg = "The suitcase is still locked. Complete the sequence first.";
    }


}

void Suitcase::use()
{
    cout << "\r" << string(80, ' ') << "\r";

    if (isUnlocked())
    {
        cout << "The suitcase is already open.\n";
        cout << "Read the note nearby.\n";
        return;
    }

    tryUnlock();
}