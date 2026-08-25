#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
class MainMenu
{
public:
    void Show();
    void DrawTitle();
    int GetChoice();
    int ShowPauseMenu();
    void ShowCredits();
    void ShowHelp();

private:
    string FormatLine(const string& text, size_t width = 33);
};

