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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
    for (int i = 1; i < height - 1; i++) // -1 so that it doesnt overlap with top of box
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
        i < static_cast<int>(lines.size()) && i < height - 2;
        i++) //static cast to convert time_t(line) to int 
    {
        //space between text and box
        pos.X = startPos.X + 2;

        //move down one line
        pos.Y = startPos.Y + 1 + i;

        SetConsoleCursorPosition(hConsole, pos);

        bool skipTyping = false;

        //print character by character
        for (int j = 0; j < static_cast<int>(lines[i].length()); j++)
        {
            //check if Z is being pressed
            if (GetAsyncKeyState('Z'))
            {
                //print the rest of the line immediately
                cout << lines[i].substr(j);

                skipTyping = true;
                break;
            }

            cout << lines[i][j];

            //wait before printing next character
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

    //remove any keys pressed during dialogue
    FlushConsoleInputBuffer(hConsole);

    cout << "\nPress Enter to continue...";

    //wait for new Enter press
    while (true)
    {
        INPUT_RECORD input; //store input 
        DWORD eventsRead; //how many event

        //read 1 console input, what input, how many events read
        ReadConsoleInput(hConsole, &input, 1, &eventsRead);

        if (input.EventType == KEY_EVENT &&  //keyboard event
            input.Event.KeyEvent.bKeyDown && //pressed down
            input.Event.KeyEvent.wVirtualKeyCode == VK_RETURN) //key enter
        {
            break;
        }
    }
}