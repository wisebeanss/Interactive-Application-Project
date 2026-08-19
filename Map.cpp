#include "Map.h"
#include <iostream>

Map::Map() {
	buildMap();
	carriageNum = 1;
}
Map::~Map() {

}
int Map::getCarriage() const {
	return carriageNum;
}
void Map::nextCarriage() {
	if (carriageNum < 6) {
		carriageNum++;
	}
	else { carriageNum = 1; }
}

void Map::buildMap() {

	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 24; j++) {

			//boundary
			if ((j == 0 && i == 0) || (j == 23 && i == 0) || (i == 6 && j == 0) || (j == 23 && i == 6)) {
				mapSize[i][j] = '+';
			}
			else if (i == 0 || i == 6) {
				mapSize[i][j] = '=';
			}
			else if (j == 0 || j == 23) {
				mapSize[i][j] = '|';
			}
			else {
				mapSize[i][j] = ' ';
			}
			
			//obj build
			if (i == 3 && j == 23) {
				mapSize[i][j] = 'D';
			}
			else if (carriageNum > 1) {
				if (i == 3 && j == 0) {
					mapSize[i][j] = 'D';
				}
			}
			
			//carriage 1
			if (carriageNum == 1) {
				if (i == 1 || i == 5) {
					if (j > 4 && j < 20 && (j % 5 != 0)) {
						mapSize[i][j] = 'H';
					}
				}
				//puzzle objects
				if ((i == 1 && j == 1) || (i == 5 && j == 1)
					|| (i == 1 && j == 4) || (i == 5 && j == 4)) {
					mapSize[i][j] = '@';
				}
				//mirror
				if ((i == 1 && j == 21) || (i == 5 && j == 21)
					|| (i == 1 && j == 16) || (i == 5 && j == 16)) {
					mapSize[i][j] = '#';
				}
			}
			//carriage 2
			else if (carriageNum == 2) {
				
				if (i == 1 || i == 5) {
					if (j > 6 && j < 20 && (j % 7 != 0)) {
						mapSize[i][j] = 'H';
					} 
				}
				if ((i == 1 && j == 2) || (i == 1 && j == 5) ||
					(i == 5 && j == 20)) {
					mapSize[i][j] = '~';
				}
				if ((i == 1 && j == 21) || (i == 5 && j == 7) ||
					(i == 5 && j == 14) || (i == 1 && j == 21)) {
					mapSize[i][j] = '^';
				}
				if (i == 5 && j == 3) {
					mapSize[i][j] = '[';
				}
				if (i == 5 && j == 4) {
					mapSize[i][j] = ']';
				}
		
				
			}


		}


	}

}

void Map::printMap() const {

	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 24; j++) {
			std::cout << mapSize[i][j] << " ";
		}	
		std::cout << "\n";
	}
}

void Map::printCarrIndicator() const {
	std::cout << "+-- -- -- -- -- --+\n";
	std::cout << "|                 |\n";
	std::cout << "|   CARRIAGE " << carriageNum << "    |\n";
	std::cout << "|                 |\n";
	std::cout << "+-- -- -- -- -- --+\n";

}
void Map::updateMap(int x, int y, char symbol) {
	if (x > 0 && x < 24 && y > 0 && y < 7) {
		mapSize[y][x] = symbol;
	}	
}

bool Map::validMove(int x, int y) {	
	return (mapSize[y][x] == ' ');
}




///*cout << R"(
//-------------------------- -------------------------- -------------------------- -------------------------- -------------------------- -------------
//|  |_ |_ |_ |_ |_ |_ |_   |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |             \
	//|                         |                          |                          |                          |                          |              \
	//|                         |                          |                          |                          |                          |               \
	//|                        | |                        | |                        | |                        | |                        | |               |
	//|                         |                          |                          |                          |                          |               /
	//|                         |                          |                          |                          |                          |              /
	//|  |_ |_ |_ |_ |_ |_ |_   |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |  |_ |_ |_ |_ |_ |_ |_    |             /
	//-------------------------- -------------------------- -------------------------- -------------------------- -------------------------- -------------
	//)" << endl;*/

	//cout << R"(
	// -------------------------
	//|  |_ |_ |_ |_ |_ |_ |_   |
	//|                         |
	//|                         |
	//|                        | |
	//|                         |
	//|                         |
	//|  |_ |_ |_ |_ |_ |_ |_   |
	// -------------------------
 //   )" << endl;
	//cout << R"(
	//  ------------------------- 
	// |  |_ |_ |_ |_ |_ |_ |_   |
	// |                         |
	// |                         |
	//| |                       | |
	// |                         |
	// |                         |
	// |  |_ |_ |_ |_ |_ |_ |_   |
	//  ------------------------- 
 //   )" << endl;
	//cout << R"(
	//  -------------
	// |              \
	// |               \
	// |                \
	//| |                |
	// |                /
	// |               /
	// |              /
	//  -------------
 //   )" << endl;
