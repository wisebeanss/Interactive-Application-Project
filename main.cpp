#include <iostream>
#include "Game.h"
#include "Map.h"
int main(void) {
	std::cout << "hello World";
	Map Map;
	Map.buildMap();
	Map.printMap();
	return 0;
}