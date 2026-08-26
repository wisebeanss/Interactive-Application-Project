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

    // Draw top
    COORD pos = startPos;
    SetConsoleCursorPosition(hConsole, pos);

    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+";

    // Draw empty box
    for (int i = 1; i < height - 1; i++)
    {
        pos.Y = startPos.Y + i;

        SetConsoleCursorPosition(hConsole, pos);

        cout << "|";

        for (int j = 0; j < width; j++)
            cout << " ";

        cout << "|";
    }

    // Draw bottom
    pos.Y = startPos.Y + height - 1;

    SetConsoleCursorPosition(hConsole, pos);

    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+";

    // Print dialogue
    for (int i = 0;
        i < static_cast<int>(lines.size()) && i < height - 2;
        i++)
    {
        pos.X = startPos.X + 2;
        pos.Y = startPos.Y + 1 + i;

        SetConsoleCursorPosition(hConsole, pos);

        for (char c : lines[i])
        {
            cout << c << flush;

            this_thread::sleep_for(
                chrono::milliseconds(typingSpeed)
            );
        }
    }

    // Put cursor below box
    pos.X = startPos.X;
    pos.Y = startPos.Y + height;

    SetConsoleCursorPosition(hConsole, pos);

    waitForEnter();
}

void Dialogue::waitForEnter()
{
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);

    // Remove any keys that were pressed during the dialogue
    FlushConsoleInputBuffer(hConsole);

    cout << "\nPress Enter to continue...";

    // Wait for a NEW Enter press
    while (true)
    {
        INPUT_RECORD input;
        DWORD eventsRead;

        ReadConsoleInput(hConsole, &input, 1, &eventsRead);

        if (input.EventType == KEY_EVENT &&
            input.Event.KeyEvent.bKeyDown &&
            input.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
        {
            break;
        }
    }
}