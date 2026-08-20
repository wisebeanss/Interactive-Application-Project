#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class InteractiveObject;
class Map
{
private:
	int carriageNum;
	int carriageRoom;
	char mapSize[13][24];
	int animFrame;
	bool offMap;
	vector<InteractiveObject*> Objects;
public:
	void resetCursorPosition() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPosition;
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(hConsole, cursorPosition);
	}
	Map();
	void updateFrame();
	void printCarrIndicator() const;
	void buildMap();
	void printMap() const;
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
	~Map();
};

