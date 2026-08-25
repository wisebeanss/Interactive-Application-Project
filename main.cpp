#include <iostream>
#include "Game.h"
#include "entirescenes.h"
#include <conio.h>
using namespace std;

int main(void)
{
    // ✅ 启动时先显示主菜单
    entirescenes mainMenu;
    mainMenu.Show();  // 选「1」才会继续往下走

    // ✅ 选「1」后初始化并启动游戏
    Game Application;
    Application.Init();

    bool running = true;
    while (running)
    {
        Application.Run();

        
        if (_kbhit())
        {
            char key = _getch();

            if (key == 27) // ESC = ASCII 27
            {
                entirescenes pauseMenu;
                int choice = pauseMenu.ShowPauseMenu();

                if (choice == 1)
                {
                 
                    continue;
                }
                else if (choice == 2)
                {
                    Application.End();
                    Application.Init();
                    mainMenu.Show();
                }
                else if (choice == 0)
                {
                    running = false;
                }
            }
        }
    }
    Application.End();
    return 0;
}