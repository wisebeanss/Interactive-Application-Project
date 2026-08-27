#include <iostream>
#include "Game.h"
#include "MainMenu.h"
#include "Player.h"
#include <conio.h>
using namespace std;

int main(void)
{
    MainMenu mainMenu;
   

    Game Application;
    
    while (true)
    {   
        mainMenu.Show(Application.getPlayer());
        Application.Init();
        Application.Run();
    }

    Application.End();
    return 0;
}