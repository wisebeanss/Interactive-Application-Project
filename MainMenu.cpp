#include "MainMenu.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string>
using namespace std;
static const string margin(35, ' ');
string MainMenu::FormatLine(const string& text, size_t width)
{
    if (text.length() >= width)
        return text.substr(0, width);
    return text + string(width - text.length(), ' ');
}

void MainMenu::DrawTitle()
{
    system("cls");
    cout << "\n\n\n";
    cout << margin << "+--------------------------------------+\n";
    cout << margin << "|                                      |\n";
    cout << margin << "|   T H E   L A S T   C A R R I A G E  |\n";
    cout << margin << "|                                      |\n";
    cout << margin << "|      A Journey Through Memory        |\n";
    cout << margin << "|                                      |\n";
    cout << margin << "+--------------------------------------+\n";
    cout << "\n";
}

void MainMenu::DrawMenu(int selected, bool isPause)
{

    if (!isPause)
    {
        cout << margin << "+---------------------------------+\n";
        cout << margin << "|         M A I N   M E N U       |\n";
        cout << margin << "+---------------------------------+\n";
        cout << margin << "|                                 |\n";
        cout << margin << "|   " << (selected == 0 ? "-->  " : "     ") << "Start Game               |\n";
        cout << margin << "|   " << (selected == 1 ? "-->  " : "     ") << "How to Play              |\n";
        cout << margin << "|   " << (selected == 2 ? "-->  " : "     ") << "Credits                  |\n";
        cout << margin << "|   " << (selected == 3 ? "-->  " : "     ") << "Exit                     |\n";
        cout << margin << "|                                 |\n";
        cout << margin << "+---------------------------------+\n";
        cout << "\n" << margin << "   Use  'W'/'S to move | Enter to confirm\n";
    }
    else
    {
        cout << margin << "+----------------------------------+\n";
        cout << margin << "|            P A U S E D           |\n";
        cout << margin << "+----------------------------------+\n";
        cout << margin << "|                                  |\n";
        cout << margin << "|   " << (selected == 0 ? "-->  " : "     ") << "Resume Game               |\n";
        cout << margin << "|   " << (selected == 1 ? "-->  " : "     ") << "Return to Main Menu       |\n";
        cout << margin << "|   " << (selected == 2 ? "-->  " : "     ") << "Exit Game                 |\n";
        cout << margin << "|                                  |\n";
        cout << margin << "+----------------------------------+\n";
        cout << "\n" << margin << "   Use 'W'/'S' to move | Enter to confirm\n";
    }
}

int MainMenu::GetChoiceInter()
{
    int selected = 0;
    int total = 4;

    while (true)
    {
        DrawTitle();
        DrawMenu(selected);

        int key = _getch();

        if (key == 'W' || key == 'w')
        {
            selected--;
            if (selected < 0) selected = total - 1;
        }
        else if (key == 'S' || key == 's')
        {
            selected++;
            if (selected >= total) selected = 0;
        }
        else if (key == 13)
        {
            return selected + 1;
        }
    }
}
void MainMenu::Show()
{
    while (true)
    {
        int choice = GetChoiceInter();

        if (choice == 1)
        {
            DrawTitle();
            cout << "\n          Starting game...\n";
            Sleep(800);
            system("cls");
            return;
        }
        else if (choice == 2)
        {
            DrawTitle();
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|       H O W   T O   P L A Y      |\n";
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   WASD  - Move Player            |\n";
            cout << margin << "|   F     - Interact / Use Object  |\n";
            cout << margin << "|   1-7   - View Inventory Item    |\n";
            cout << margin << "|   ESC   - Pause Game             |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Solve puzzles, collect items,  |\n";
            cout << margin << "|   and uncover the truth.         |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Press any key to return...     |\n";
            cout << margin << "+----------------------------------+\n";
            (void)_getch();
        }
        else if (choice == 3)
        {
            DrawTitle();
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|           C R E D I T S          |\n";
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   THE LAST CARRIAGE              |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Concept & Narrative:           |\n";
            cout << margin << "|   Psychological Theme & Design   |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Programming & Design:          |\n";
            cout << margin << "|   Your Name / Team               |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Special Thanks:                |\n";
            cout << margin << "|   Everyone who helped along      |\n";
            cout << margin << "|   the way.                       |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Press any key to return...     |\n";
            cout << margin << "+----------------------------------+\n";
            (void)_getch();
        }
        else if (choice == 4)
        {
            DrawTitle();
            cout << "\n          Goodbye...\n";
            Sleep(800);
            exit(0);
        }
    }
}
int MainMenu::ShowPauseMenu()
{
    int selected = 0;
    int total = 3;

    while (true)
    {
        system("cls");
        cout << "\n\n\n";
        DrawMenu(selected, true);

        int key = _getch();
        if (key == 'W' || key == 'w') { selected--; if (selected < 0) selected = total - 1; }
        else if (key == 'S' || key == 's') { selected++; if (selected >= total) selected = 0; }
        else if (key == 13)
        {
            return selected + 1; 
        }
    }
}

void MainMenu::ShowCredits()
{
    DrawTitle();
    cout << "Credits content here...\n";
}