#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <conio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "Note.h"
#include "Map.h"
#include "Puzzle.h"

using namespace std;
class Game
{
private:
	Map map;
	Player player;
public:
	Game();
	~Game();
	void Init();
	void Run();
	void End();
};

