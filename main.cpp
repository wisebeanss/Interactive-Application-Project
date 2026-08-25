#include <iostream>
#include "Game.h"
#include "MainMenu.h"
#include <conio.h>
using namespace std;

int main(void)
{   
    
    MainMenu Mainmenu;
    Game Application;
    Application.Init();
    bool MainMenuRunning = false; // set this to true when main menu is done
    bool GameRunning = true; // set this to false when main menu is done
    while (MainMenuRunning) {
        //Mainmenu.Run();
    }
    while (GameRunning)
    {
        //Mainmenu.Run();

        Application.Run();

        
        //if (_kbhit())
        //{
        //    char key = _getch();

        //    if (key == 27) // ESC = ASCII 27
        //    {
        //        MainMenu pauseMenu;
        //        int choice = pauseMenu.ShowPauseMenu();

        //        if (choice == 1)
        //        {
        //         
        //            continue;
        //        }
        //        else if (choice == 2)
        //        {
        //            Application.End();
        //            Application.Init();
        //            mainMenu.Show();
        //        }
        //        else if (choice == 0)
        //        {
        //            running = false;
        //        }
        //    }
        //}
    }
    Application.End();
    return 0;
}