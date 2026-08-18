#pragma once
#include <iostream>
class Map
{
private:
	int carriageNum;
	char mapSize[7][24];
	
public:
	Map();
	void printCarrIndicator() const;
	void buildMap();
	void printMap() const;
	void mapTile(int posX, int posY, char symbol);
	void updateMap(int x, int y, char symbol);
	bool validMove(int x, int y);
	~Map();
};

