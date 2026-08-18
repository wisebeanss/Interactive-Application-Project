#include <iostream>
#include "Game.h"
#include "Map.h"
int main(void) {
	Map Map; 
	Map.buildMap();
	Map.printMap();
	return 0;
}