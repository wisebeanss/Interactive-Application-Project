#include "Dialogue.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <Windows.h>

Dialogue::Dialogue()
{
    typingSpeed = 50;
}

void Dialogue::show(const vector<string>& lines, int width, int height, int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //get console to control cursor

    COORD startPos;
    startPos.X = x;
    startPos.Y = y;

    //draw top
    COORD pos = startPos;
    SetConsoleCursorPosition(hConsole, pos);

    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+";

    //draw side box
    for (int i = 1; i < height - 1; i++)
    {
        pos.Y = startPos.Y + i;

        SetConsoleCursorPosition(hConsole, pos);

        cout << "|";

        for (int j = 0; j < width; j++)
            cout << " ";

        cout << "|";
    }

    //draw bottom
    pos.Y = startPos.Y + height - 1;

    SetConsoleCursorPosition(hConsole, pos);

    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+";

    //print dialogue
    for (int i = 0;
        i < static_cast<int>(lines.size()) && i < height - 2; //height for spacing,static cast to convert size_t to int (lines)
        i++)
    {
        //spacing btwn text and box
        pos.X = startPos.X + 2;
        //line by line
        pos.Y = startPos.Y + 1 + i;

        SetConsoleCursorPosition(hConsole, pos);

        for (char c : lines[i])
        {
            // flush to make character appear immediately for typewrite effect 
            cout << c << flush;

            //wait 50ms to print next character
            this_thread::sleep_for(
                chrono::milliseconds(typingSpeed)
            );
        }
    }

    //put cursor below box
    pos.X = startPos.X;
    pos.Y = startPos.Y + height;

    SetConsoleCursorPosition(hConsole, pos);

    waitForEnter();
}

void Dialogue::waitForEnter()
{
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);

    //remove any keys that were pressed during the dialogue
    FlushConsoleInputBuffer(hConsole);

    cout << "\nPress Enter to continue...";

    //wait for new Enter press
    while (true)
    {
        INPUT_RECORD input; //store input
        DWORD eventsRead; //how many input

        //read 1 console input event,what input, how many events
        ReadConsoleInput(hConsole, &input, 1, &eventsRead);

        if (input.EventType == KEY_EVENT && //keyboard event
            input.Event.KeyEvent.bKeyDown && //key was pressed down
            input.Event.KeyEvent.wVirtualKeyCode == VK_RETURN) //key = enter
        {
            break;
        }
    }
}