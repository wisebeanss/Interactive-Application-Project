#include "Map.h"
#include <iostream>

Map::Map() {
	buildMap();
	carriageNum = 1;
	carriageRoom = 1;
}
Map::~Map() {

}
int Map::getCarriage() const {
	return carriageNum;
}
int Map::getRoom() const {
	return carriageRoom;
}
void Map::nextCarriage() {
	if (carriageNum < 6) {
		carriageNum++;
	}
	else { carriageNum = 1; }
}
void Map::nextRoom() {
	if (carriageRoom < 3) {
		carriageRoom++;
	}
	else { carriageRoom = 1; }
}

void Map::buildMap() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 24; j++) {
			mapSize[i][j] = ' ';
		}
	}

	if (carriageRoom == 1) {
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
						mapSize[i][j] = 'B';
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
					//if ((i == 1 && j == 21) || (i == 5 && j == 7) ||
					//	(i == 5 && j == 14) || (i == 1 && j == 21)) {
					//	mapSize[i][j] = '^';
					//}
					if (i == 5 && j == 3) {
						mapSize[i][j] = '[';
					}
					if (i == 5 && j == 4) {
						mapSize[i][j] = ']';
					}
				}
				//carriage 3
				else if (carriageNum == 3) {
					if (carriageRoom == 1) {
						if (i == 1 || i == 5) {
							if (j > 6 && j < 19 && (j % 7 != 0) && (j % 7 != 1)) {
								mapSize[i][j] = 'H';
							}
						}
						if (i == 1 && j == 2) {
							mapSize[i][j] = '^';
						}
						if (i == 5 && j == 5) {
							mapSize[i][j] = '@';
						}
						if ((i == 1 && j == 5) || (i == 5 && j == 2)) {
							mapSize[i][j] = 'A';
						}
						if (i == 0 && j == 21) {
							mapSize[i][j] = '_';
						}
					}
				}
				else if (carriageNum == 4) {
					if (i == 1 || i == 5) {
						if (j > 6 && j < 19 && (j % 7 != 0) && (j % 7 != 1)) {
							mapSize[i][j] = 'H';
						}
					}
					if (i == 1 && j == 3) {
						mapSize[i][j] = '[';
					}
					if (i == 1 && j == 4) {
						mapSize[i][j] = ']';
					}
					if ((i == 5 && j == 5) || (i == 5 && j == 22) ||
						(i == 1 && j == 14)) {
						mapSize[i][j] = '~';
					}
				}

			}


		}
	}
	//////////////////roooms////////////////////////
	else if (carriageRoom == 2) {
		for (int i = 0; i < 7; i++) {

			for (int j = 0; j < 12; j++) {

				//boundary
				if ((j == 0 && i == 0) || (j == 11 && i == 0) || (i == 6 && j == 0) || (j == 11 && i == 6)) {
					mapSize[i][j] = '+';
				}
				else if (i == 6 && j == 2) {
					mapSize[i][j] = '_';
				}
				else if (i == 0 || i == 6) {
					mapSize[i][j] = '=';
				}
				else if (j == 0 || j == 11) {
					mapSize[i][j] = '|';
				}
				else {
					mapSize[i][j] = ' ';
				}

				if (carriageNum == 3) {
					if (i == 1 && j == 5) {
						mapSize[i][j] = '^';
					}
					if (i == 1 && j == 9) {
						mapSize[i][j] = '~';
					}
					if (i == 5 && j == 9) {
						mapSize[i][j] = 'W';
					}
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
	std::cout << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";
	std::cout << "|                 |    |                 |\n";
	std::cout << "|   CARRIAGE " << carriageNum << "    |    |     ROOM   " << carriageRoom << "    |\n";
	std::cout << "|                 |    |                 |\n";
	std::cout << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";

}
void Map::updateMap(int x, int y, char symbol) {
	if (x > 0 && x < 24 && y > 0 && y < 7) {
		mapSize[y][x] = symbol;
	}	
}

bool Map::validMove(int x, int y) {	
	return (mapSize[y][x] == ' ');
}

vector<InteractiveObject*> Map::getObjects() {
	return Objects;
}
void Map::setObjects(InteractiveObject* object) {
	Objects.push_back(object);
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
