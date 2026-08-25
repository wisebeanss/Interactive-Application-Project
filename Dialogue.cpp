#include "Dialogue.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Dialogue::Dialogue()
{
    typingSpeed = 50; // milliseconds per character
}

void Dialogue::show(const vector<string>& lines)
{
    const int width = 42;
    const std::string margin(35, ' ');

    // Top of box
    cout << margin << "+------------------------------------------+\n";
    //cout << margin << "|                                          |\n";

    // Print each dialogue line
    for (const string& line : lines)
    {
        cout << margin << "| ";

        // Typewriter animation
        for (char c : line)
        {
            cout << c << flush;
            this_thread::sleep_for(
                chrono::milliseconds(typingSpeed)
            );
        }

        // Fill remaining space
        int spaces = width - 2 - static_cast<int>(line.length());

        for (int i = 0; i < spaces; i++)
        {
            cout << ' ';
        }

        cout << " |\n";
    }

    // Bottom of box
    //cout << margin << "|                                          |\n";
    cout << margin << "+------------------------------------------+\n";
}