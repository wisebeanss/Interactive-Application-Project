#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <algorithm>
#include "Doors.h"
#include "Mirrors.h"
#include "Clocks.h"
#include "Timer.h"
using namespace std;


class InteractiveObject;

class Map
{
private:
	int carriageNum;
	int carriageRoom;
	int animFrame;
	bool offMap;
	bool renderMap;
	vector<InteractiveObject*> Objects;
	
public:
	int timerSeconds;
	Timer timer;
	Timer& getTimerObject();
	char mapSize[13][24];
	void resetCursorPosition();
	bool isMapRendered();
	void setMapRendered(bool rendered);
	void updateFrame();
	//void printCarrIndicator() const;
	void printSidebar(int carriageNum, int carriageRoom, bool uiActive, const std::string uiBuffer[13] = nullptr) const;
	void buildMap();
	//void printMap() const;
	void mapTile(int posX, int posY, char symbol);
	void updateMap(int x, int y, char symbol);
	bool validMove(int x, int y);
	vector<InteractiveObject*> getObjects();
	void setObjects(InteractiveObject* object);
	int getCarriage() const;
	void nextCarriage(); //debug
	int getRoom() const;
	void nextRoom(); //debug
	void clearObjects();
	bool getOffMap();
	void setOffMap(bool printmap);
	void updateTimer();
	void reduceTimer();
	Map();
	~Map();
	
};
Map& getGameMap();
