#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include "Map.h"
using namespace std;
class MainMenu
{
public:
    MainMenu();
    ~MainMenu();
    void Show();
    void DrawTitle();
    int GetChoiceInter();
    int ShowPauseMenu();
    void ShowCredits();
    void ShowHelp();
    int getMenuChoice(int total, bool isPause);
    void showInfoScreen(const std::string& title, const std::vector<std::string>& lines);
    bool selectCarriage();
private:
    string FormatLine(const string& text, size_t width);
    void DrawMenu(int selected, bool isPause = false);
    Map& map;
};

