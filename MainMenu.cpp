#include "MainMenu.h"
#include<conio.h>
#include<string>
using namespace std;
string MainMenu::FormatLine(const string& text, size_t width)
{
    if (text.length() >= width)
        return text.substr(0, width);
    return text + string(width - text.length(), ' ');
}

void MainMenu::DrawTitle() {
    system("cls");
    string margin(35, ' ');

    cout << "\n\n\n";
    cout << margin << "+--------------------------------------+\n";
    cout << margin << "|                                      |\n";
    cout << margin << "|   T H E   L A S T   C A R R I A G E  |\n";
    cout << margin << "|                                      |\n";
    cout << margin << "|      A Journey Through Memory        |\n";
    cout << margin << "|                                      |\n";
    cout << margin << "+--------------------------------------+\n";
    cout << "\n\n";
}
void MainMenu::Show()
{
    int choice = -1;
    string margin(35, ' ');

    while (choice != 0)
    {
        DrawTitle();

        cout << margin << "+---------------------------------+\n";
        cout << margin << "|         M A I N   M E N U       |\n";
        cout << margin << "+---------------------------------+\n";
        cout << margin << "|                                 |\n";
        cout << margin << "|   --> Start Game                |\n";
        cout << margin << "|       How to Play               |\n";
        cout << margin << "|       Credits                   |\n";
        cout << margin << "|       Exit                      |\n";
        cout << margin << "|                                 |\n";
        cout << margin << "+---------------------------------+\n";

        choice = GetChoice();

        if (choice == 1)
        {
            cout << "\n" << margin << "   Starting game...\n";
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
            cout << margin << "|                                  |\n";
            cout << margin << "|   Solve puzzles, collect items,  |\n";
            cout << margin << "|   and uncover the truth.         |\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   Press any key to return...     |\n";
            cout << margin << "+----------------------------------+\n";
            _getch();
        }
        else if (choice == 3)
        {
            DrawTitle();
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|           C R E D I T S          |\n";
            cout << margin << "+----------------------------------+\n";
            cout << margin << "|                                  |\n";
            cout << margin << "|   THE CARRIAGE                   |\n";
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
            _getch();
        }
        else if (choice == 0)
        {
            cout << "\n" << margin << "   Goodbye...\n";
            Sleep(800);
            exit(0);
        }
        else
        {
            cout << "\n" << margin << "   Invalid choice! Try again.\n";
            Sleep(1200);
        }
    }
}

int MainMenu::GetChoice()
{
    string input;
    cin >> input;
    if (input.empty() || input[0] < '0' || input[0] > '9')
        return -1;
    return input[0] - '0';
}

void MainMenu::ShowCredits()
{
    DrawTitle();
    cout << "Credits content here...\n";
}
int MainMenu::ShowPauseMenu()
{
    system("cls");
    string margin(35, ' ');

    cout << "\n\n\n";
    cout << margin << "+----------------------------------+\n";
    cout << margin << "|       P A U S E D                |\n";
    cout << margin << "+----------------------------------+\n";
    cout << margin << "|                                  |\n";
    cout << margin << "|   -->  Resume Game               |\n";
    cout << margin << "|        Return to Main Menu       |\n";
    cout << margin << "|        Exit Game                 |\n";
    cout << margin << "|                                  |\n";
    cout << margin << "+----------------------------------+\n";
    cout << "\n" << margin << "   Enter your choice [0-2]: ";

    int choice = GetChoice();
    while (choice < 0 || choice > 2)
    {
        cout << "\n" << margin << "   Invalid choice! Try again: ";
        choice = GetChoice();
    }
    return choice;
}