#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include <vector>
#include "Player.h"
#include "InteractiveObject.h"
#include "Map.h"

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

