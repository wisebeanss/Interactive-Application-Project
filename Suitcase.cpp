#include "Suitcase.h"
#include <iostream>
#include <string>
#include "Dialogue.h"
#include "Doors.h"
#include "Windows.h"
#include "Sound.h"
using namespace std;
Sound suitcase;
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

void Suitcase::clearQuestion(COORD startPos, int lines)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < lines; i++)
    {
        COORD pos;
        pos.X = startPos.X;
        pos.Y = startPos.Y + i;

        SetConsoleCursorPosition(hConsole, pos);

        cout << string(100, ' ');
    }

    // Return cursor to the original question position
    SetConsoleCursorPosition(hConsole, startPos);
}

void Suitcase::tryUnlock()
{
    Dialogue dialogue;
    string hintMsg;
    if (roomID == 2)
    {
        suitcase.PlayError();
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        canunlock = hasAllPhotos();
        if (!canunlock)
        {
            cout << "\n" << hintMsg << "\n";
        }
        if (canunlock)
        {
            suitcase.PlaySuitcase();
            dialogue.show({
            "You stare at the completed image.",
            "\"Was I really there?\"",
            "A note has appeared nearby.",
                },42, 10, 35, 18);


            system("cls");
            unlocked = canunlock;
        }
    }
    else if (roomID == 3)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(hConsole, &info);

        COORD questionPos = info.dwCursorPosition;

        hintMsg = "give the order of the time of the calls(XXXXXXXXXXXXXXXX): ";
        clearQuestion(questionPos, 1);
        
        if (!canunlock)
        {
            string answer;
            cout << hintMsg;
            cin >> answer;
            if (answer == "1132113411351137")
            {
                suitcase.PlaySuitcase();
                canunlock = true;
            }
            if (canunlock == false)
            {
                dialogue.show({
                      "That doesn't seem right..",
                      "Two minutes have been deducted.",

                });
                system("cls");
                getGameMap().timer.decreaseTime(2 * 60);
                suitcase.PlayError();
            }
        }
        if (canunlock)
        {
            dialogue.show({
           "You stare at the clock..",
           "\"11:35...\"",
           "You remember blaming yourself for what happened.",
           "But the calls continued after the clock stopped.",
           "A thought slowly surfaces.",
           "\"I wasn't there.\"",
           "You step back.",
           "The suitcase opens."
                }, 54, 10, 30, 18);

            

            system("cls");
            unlocked = canunlock;
        }
        //1132 1134 1135 1137
    }
    if (roomID == 4)
    {
        suitcase.PlayError();
        hintMsg = "The suitcase is still locked. Find all 3 photos first.\nPieces collected: " + to_string(noOfPhotos) + "/3";
        canunlock = hasAllPhotos();
        if (!canunlock)
        {
            cout << "\n" << hintMsg ;
        }
        if (canunlock)
        {
            dialogue.show({
            "You place the fragments together.",
            "The photograph slowly becomes whole.",
            "You see yourself as a child,",
            "sitting beside them.",
            "You stare at the faded face beside yours.",
            "\"I remember you\"",
            "Your fingers tighten around the photograph.",
            "\"I just wish I didn't.\"",
            "The suitcase opens.",
             }, 44, 11, 35, 18);
         
            system("cls");
            unlocked = canunlock;
        }
    }
    if (roomID == 5)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(hConsole, &info);

        COORD questionPos = info.dwCursorPosition;


        if (!canunlock)
        {
            cout << "\r" << string(80, ' ') << "\r";
            cout << "Which letter was written last: ";


            string answer;
            cin >> answer;

            clearQuestion(questionPos, 1);

            if (answer == "D" || answer == "d")
            {
                canunlock = true;
            }
            else
            {
                suitcase.PlayError();
                dialogue.show({
                     "That doesn't seem right..",
                     "Two minutes have been deducted.",

                    });



                system("cls");
                getGameMap().timer.decreaseTime(2 * 60);
            }
        }
        if (canunlock)
        {
            dialogue.show({
            "Letters lie scattered across the table,",
            "written one after another as hope slowly faded.",
            "Two notes are pinned to the wall.",
            "\"The last letter was written after I stopped expecting an answer.\"",
            "\"I stopped calling before I stopped writing.\"",
            "Three letters bear dates, marking the days she still waited.",
            "And one, without a date.",
            "Written after she had finally stopped waiting entirely.\n",
            "You choose the letter with no date.",
            "The safe clicks open.\n",
                }, 68, 11, 20, 18);

            system("cls");

            unlocked = canunlock;
        }
    }
    if (roomID == 6)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(hConsole, &info);

        COORD questionPos = info.dwCursorPosition;

        string answer;
        if (!canunlock)
        {
            cout << "\r" << string(80, ' ') << "\r";
            cout << "Which drawer holds the truth: ";

            cin >> answer;
            clearQuestion(questionPos, 1);
            if (answer == "5")
            {
                canunlock = true;
            }
            else
            {
                suitcase.PlayError();
                dialogue.show({
                    "That doesn't seem right..",
                    "Two minutes have been deducted.",
                    });


                system("cls");
                getGameMap().timer.decreaseTime(2 * 60);
            }
        }
        if (canunlock)
        {
            dialogue.show({
            "You pull open Drawer 5,",
            "a folded piece of paper lies inside.",
            "You recognize the handwriting immediately.",
            "\"It's yours. \"",
            "You unfold it.",
            "There is only one sentence:",
            "\"You already knew.\"",
            "All this time, you had been searching for an answer.",
            "In the train, photographs, empty seats",
            "But the answer was never somewhere else.",
            "It was always with you.",
            "\"I knew...\"",
            "For the first time, you don't look away. ",
            "The doors unlocks. ",
                }, 56, 10, 26, 18);


            system("cls");

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