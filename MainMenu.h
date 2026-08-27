#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include <vector>
#include "Map.h"
#include "Player.h"""
using namespace std;
class MainMenu
{
public:
    MainMenu();
    ~MainMenu();
    void Show(Player& player);
    void DrawTitle();
    int GetChoiceInter();
    int ShowPauseMenu();
    void ShowCredits();
    void ShowHelp();
    int ShowGameOverMenu(Player& player);
    void DrawGameOverMenu(int selected);
    int getMenuChoice(int total, bool isPause);
    void showInfoScreen(const std::string& title, const std::vector<std::string>& lines);
    void selectCarriage();
private:
    string FormatLine(const string& text, size_t width);
    void DrawMenu(int selected, bool isPause = false);
    Map& map;
};

