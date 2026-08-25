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
    if (roomID == 2 || roomID == 4)
    {
        noOfPhotos = noOfPhotos + 1;
    }
}

bool Suitcase::hasAllPhotos()
{
    if (roomID == 2 || roomID == 4)
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

void Suitcase::tryUnlock()
{
    string hintMsg;
    if (roomID == 2)
    {
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        if (!canunlock)
        {
            canunlock = hasAllPhotos();
            cout << "\n" << hintMsg << "\n";
        }
        if (canunlock)
        {
            cout << "\r";
            cout << "A hand reaching out.\n";
            cout << "A face turned away.\n";
            cout << "Someone sitting beside you.\n";
            cout << "You stare at the completed image.\n";
            cout << "Was I really there?\n";
            cout << "\nA note has appeared nearby.\n";
            unlocked = canunlock;
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
        }
        //1132 1134 1135 1137
    }
    if (roomID == 4)
    {
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        if (!canunlock)
        {
            canunlock = hasAllPhotos();
            cout << "\n" << hintMsg << "\n";
        }
        if (canunlock)
        {
            cout << "\r";
            cout << "You place the fragments together.\n";
            cout << "The photograph slowly becomes whole.\n";
            cout << "You see yourself as a child.\n";
            cout << "Then, sitting beside them.\n";
            cout << "Then, standing beside them.\n";
            cout << "You stare at the faded face beside yours.\n";
            cout << "\"I remember you\"\n";
            cout << "Your fingers tighten around the photograph.\n";
            cout << "\"I just wish I didn't.\"\n";
            cout << "The suitcase opens\n";
            unlocked = canunlock;
        }
    }
    if (roomID == 5)
    {
        hintMsg = "which letter was written last :";
        if (!canunlock)
        {
            cout << "\n" << hintMsg << "\n";
            string answer;
            cin >> answer;
            if (answer == "D")
            {
                canunlock = true;
            }
        }
        if (canunlock)
        {
            cout << "Letters lie scattered across the table,\n";
            cout << "written one after another as hope slowly faded.\n";
            cout << "Two notes are pinned to the wall.\n";
            cout << "\"The last letter was written after I stopped expecting an answer.\"\n";
            cout << "\"I stopped calling before I stopped writing.\"\n";
            cout << "Three letters bear dates, marking the days she still waited.\n";
            cout << "And one - without a date -\n";
            cout << "written after she had finally stopped waiting entirely.\n";
            cout << "You choose the letter with no date.\n";
            cout << "The safe clicks open.\n";

            unlocked = true;
        }
    }
}

void Suitcase::use()
{
    cout << "\r";

    if (isUnlocked())
    {
        cout << "The suitcase is already open.\n";
        cout << "Read the note nearby.\n";
        return;
    }

    tryUnlock();
}