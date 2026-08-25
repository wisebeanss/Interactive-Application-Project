#include "Dialogue.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;

Dialogue::Dialogue()
{
    typingSpeed = 50;
}

void Dialogue::show(const vector<string>& lines)
{
    const int width = 42;
    const int height = 10;
    const string margin(35, ' ');

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get current cursor position
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    COORD startPos = consoleInfo.dwCursorPosition;

    // =========================
    // DRAW ENTIRE BOX FIRST
    // =========================

    cout << margin << "+------------------------------------------+\n";

    for (int i = 0; i < height - 2; i++)
    {
        cout << margin << "|                                          |\n";
    }

    cout << margin << "+------------------------------------------+\n";

    // =========================
    // PRINT TEXT INSIDE BOX
    // =========================

    for (int i = 0; i < lines.size() && i < height - 2; i++)
    {
        COORD textPos;

        textPos.X = startPos.X + static_cast<SHORT>(margin.length()) + 2;
        textPos.Y = startPos.Y + 1 + i;

        SetConsoleCursorPosition(hConsole, textPos);

        for (char c : lines[i])
        {
            cout << c << flush;

            this_thread::sleep_for(
                chrono::milliseconds(typingSpeed)
            );
        }
    }

    // Move cursor below the dialogue box
    COORD endPos;

    endPos.X = startPos.X;
    endPos.Y = startPos.Y + height;

    SetConsoleCursorPosition(hConsole, endPos);
}