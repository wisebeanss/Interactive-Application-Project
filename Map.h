#pragma once
#include <iostream>
#include <vector>
using namespace std;
class InteractiveObject;
class Map
{
private:
	int carriageNum;
	int carriageRoom;
	char mapSize[7][24];
	vector<InteractiveObject*> Objects;
public:
	Map();
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
	~Map();
};

