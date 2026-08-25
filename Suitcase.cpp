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
    canunlock = false;
}

bool Suitcase::isUnlocked()
{
    return unlocked;
}

void Suitcase::collectPhoto()
{
    if (roomID == 2)
    {
        noOfPhotos = noOfPhotos + 1;
    }
}

bool Suitcase::hasAllPhotos()
{
    if (roomID == 2)
    {
        return noOfPhotos == 3;
    }
    return false;
}

void Suitcase::markPuzzleSolved()
{
    puzzleSolved = true;
}

void Suitcase::setProgressState(int s)
{
    progressState = s;
}

bool Suitcase::tryUnlock()
{
    string hintMsg;
    if (roomID == 2)
    {
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        if (!canunlock)
        {
            canunlock = hasAllPhotos();
            cout << "\n" << hintMsg << "\n";
            return false;
        }
        if (canunlock)
        {
            cout << "\r" << string(80, ' ') << "\r";
            cout << "A hand reaching out.\n";
            cout << "A face turned away.\n";
            cout << "Someone sitting beside you.\n";
            cout << "You stare at the completed image.\n";
            cout << "Was I really there?\n";
            cout << "\nA note has appeared nearby.\n";
            unlocked = canunlock;
            return true;
        }
    }
    else if (roomID == 3)
    {
        hintMsg = "give the order of the time of the calls";
        if (!canunlock)
        {
            string answer;
            int i = 1;
            cout << "\n" << hintMsg;
            cout << "\ntime" << i << ": ";
            cin >> answer;
            i++;
            if (answer == "1132")
            {
                cout << "time" << i << ": ";
                cin >> answer;
                i++;
                if (answer == "1134")
                {
                    cout << "time" << i << ": ";
                    cin >> answer;
                    i++;
                    if (answer == "1135")
                    {
                        cout << "time" << i << ": ";
                        cin >> answer;
                        i++;
                        if (answer == "1137")
                        {
                            canunlock = true;
                        }
                    }
                }
            }
            return false;
        }
        if (canunlock)
        {
            cout << "You stare at the clock..\n";
            cout << "\"11:35...\"\n";
            cout << "You remember blaming yourself for what happened.\n";
            cout << "But the calls continued after the clock stopped.\n";
            cout << "A thought slowly surfaces.\n";
            cout << "\"I wasn't there.\"\n";
            cout << "You step back.\n";
            unlocked = canunlock;
            return true;
        }
        //1132 1134 1135 1137
    }
    else if (roomID == 4)
    {
        unlocked = (progressState >= 2);
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