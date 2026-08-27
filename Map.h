#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <algorithm>
#include "MapObjects.h"
#include "Timer.h"       
#include "Suitcase.h"   
#include <array>
#include "Vector.h"
using namespace std;

class InteractiveObject;
class Player;
class Suitcase; 

class Map
{
private:
	int carriageNum;
	int carriageRoom;
	int animFrame;
	bool offMap;
	bool renderMap;
	Vector<InteractiveObject*> Objects;
	Suitcase* suitcasePtr = nullptr; 
	bool noteSpawned = false;
	array<bool, 3> endingsReached;
	bool ended;

public:
	int timerSeconds;
	Timer timer; 
	Timer& getTimerObject();
	char mapSize[13][24];
	void resetCursorPosition();
	bool isMapRendered();
	void setMapRendered(bool rendered);
	void updateFrame();
	void printSidebar(int carriageNum, int carriageRoom, bool uiActive, Player& player, const std::string uiBuffer[13] = nullptr) const;
	void printDialogueBox(bool uiActive, const std::string textBuffer[7] = nullptr) const;
	void buildMap();
	void mapTile(int posX, int posY, char symbol);
	void updateMap(int x, int y, char symbol);
	bool validMove(int x, int y);
	void printMap(int marginSize);

	Vector<InteractiveObject*>& getObjects();
	void setObjects(InteractiveObject* object);
	void removeObject(InteractiveObject* object);
	void clearObjects();

	int getCarriage() const;
	void nextCarriage();
	void setCarriage(int num);
	int getRoom() const;
	void nextRoom();
	void prevRoom();

	void bindSuitcase(Suitcase* ptr);
	Suitcase* getSuitcase();
	void checkSuitcaseUnlock();

	bool getOffMap();
	void setOffMap(bool printmap);
	void updateTimer();
	void reduceTimer();
	Map();
	~Map();

	//Ending
	bool isEnded();
	void setEnded(bool ended);
	void setEndingReached(int id);
	bool getEndingReached(int id) const;
	bool isThereEndings() const;
};
Map& getGameMap();