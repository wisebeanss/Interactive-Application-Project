#include <iostream>
#include "Game.h"
#include "MainMenu.h"
#include <conio.h>
using namespace std;

int main(void)
{
    MainMenu mainMenu;
   

    Game Application;
    
    while (true)
    {   
        mainMenu.Show();
        Application.Init();
        Application.Run();
    }

    Application.End();
    return 0;
}