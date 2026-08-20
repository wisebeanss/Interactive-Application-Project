#include "Map.h"
#include <iostream>

Map::Map() {
	buildMap();
	carriageNum = 1;
	carriageRoom = 1;
	animFrame = 0;
}
Map::~Map() {

}
bool Map::isMapRendered() {
	return renderMap;
}
void Map::setMapRendered(bool rendered) {
	renderMap = rendered;
}
Map& getGameMap() {
	static Map map;
	return map;
}
void Map::resetCursorPosition() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsole, cursorPosition);
}

void Map::updateFrame() {
	animFrame++;
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
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 24; j++) {
			mapSize[i][j] = ' ';
		}
	}

	if (carriageRoom == 1) {

		for (int j = 0; j < 24; j++) {

			mapSize[0][j] = 'X';
			mapSize[12][j] = 'X';

			int mountainOffset = (j + (animFrame / 2)) % 8;
			if (mountainOffset == 0) mapSize[1][j] = '/';
			else if (mountainOffset == 1)  mapSize[1][j] = '\\';

			int poleOffset = (j + animFrame) % 7;
			if (poleOffset == 0) mapSize[2][j] = 'i';
			else if (poleOffset == 1) mapSize[2][j] = '-';
			else if (poleOffset == 2) mapSize[2][j] = '-';
			else if (poleOffset == 3) mapSize[2][j] = 'i';


			int mountainOffset2 = (j + (animFrame / 3)) % 12;
			if (mountainOffset2 == 0) mapSize[11][j] = '/';
			else if (mountainOffset2 == 1)  mapSize[11][j] = '\\';

			int poleOffset2 = (j + animFrame) % 9;
			if (poleOffset2 == 0) mapSize[10][j] = 'i';
			else if (poleOffset2 == 1) mapSize[10][j] = '-';
			else if (poleOffset2 == 2) mapSize[10][j] = '-';
			else if (poleOffset2 == 3) mapSize[10][j] = 'i';
		}
	
	int trainOffset = 3;			
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 24; j++) {
			int gridY = trainOffset + i;
			//boundary
			if ((j == 0 && i == 0) || (j == 23 && i == 0) || (i == 6 && j == 0) || (j == 23 && i == 6)) {
				mapSize[gridY][j] = '+';
			}
			else if (i == 0 || i == 6) {
				mapSize[gridY][j] = '=';
			}
			else if (j == 0 || j == 23) {
				mapSize[gridY][j] = '|';
			}
			else {
					mapSize[gridY][j] = ' ';
			}

			//obj build
			//if (i == 3 && j == 23) {
			//	mapSize[gridY][j] = 'D';
			//}

			if (carriageNum > 1) {
				if (i == 3 && j == 0) {
					mapSize[gridY][j] = 'B';
				}
			}

			//carriage 1
			if (carriageNum == 1) {
				if (i == 1 || i == 5) {
					if (j > 4 && j < 20 && (j % 5 != 0)) {
						mapSize[gridY][j] = 'H';
					}
				}
				//puzzle objects
				if ((i == 1 && j == 1) || (i == 5 && j == 1)
					|| (i == 1 && j == 4) || (i == 5 && j == 4)) {
					mapSize[gridY][j] = '@';

				}
				//mirror
				if ((i == 1 && j == 21) || (i == 5 && j == 21)
					|| (i == 1 && j == 16)) {
					mapSize[gridY][j] = '&';

				}
			}
			//carriage 2
			else if (carriageNum == 2) {
				if (i == 1 || i == 5) {
					if (j > 6 && j < 20 && (j % 7 != 0)) {
						mapSize[gridY][j] = 'H';
					}
				}
				if ((i == 1 && j == 2) || (i == 1 && j == 5) ||
					(i == 5 && j == 20)) {
					mapSize[gridY][j] = '~';
				}
				//if ((i == 1 && j == 21) || (i == 5 && j == 7) ||
				//	(i == 5 && j == 14) || (i == 1 && j == 21)) {
				//	mapSize[i][j] = '^';
				//}
				if (i == 5 && j == 3) {
					mapSize[gridY][j] = '[';
				}
				if (i == 5 && j == 4) {
					mapSize[gridY][j] = ']';
				}
			}
			//carriage 3
			else if (carriageNum == 3) {
				if (carriageRoom == 1) {
					if (i == 1 || i == 5) {
						if (j > 6 && j < 19 && (j % 7 != 0) && (j % 7 != 1)) {
							mapSize[gridY][j] = 'H';
						}
					}
					if (i == 1 && j == 2) {
						mapSize[gridY][j] = '^';
					}
					if (i == 5 && j == 5) {
						mapSize[gridY][j] = '@';
					}
					if ((i == 1 && j == 5) || (i == 5 && j == 2)) {
						mapSize[gridY][j] = 'A';
					}
					if (i == 0 && j == 21) {
						mapSize[gridY][j] = '_';
					}
				}
			}
			else if (carriageNum == 4) {
				if (i == 1 || i == 5) {
					if (j > 6 && j < 19 && (j % 7 != 0) && (j % 7 != 1)) {
						mapSize[gridY][j] = 'H';
					}
				}
				if (i == 1 && j == 3) {
					mapSize[gridY][j] = '[';
				}
				if (i == 1 && j == 4) {
					mapSize[gridY][j] = ']';
				}
				if ((i == 5 && j == 5) || (i == 5 && j == 22) ||
					(i == 1 && j == 14)) {
					mapSize[gridY][j] = '~';
				}
			}
			else if (carriageNum == 5) {
				if (i == 1 || i == 5) {
					if (j > 5 && j < 17 && (j % 7 != 0) && (j % 8 != 1)) {
						mapSize[gridY][j] = 'H';
					}
				}
				if ((i == 1 && j == 2) || (i == 5 && j == 5)) {
					mapSize[gridY][j] = '^';
				}
				if ((i == 1 && j == 18) || (i == 1 && j == 21) ||
					(i == 5 && j == 18) || (i == 5 && j == 21)) {
					mapSize[gridY][j] = '?';
				}

			}
			else if (carriageNum == 6) {
				if ((i == 1 && j == 5) || (i == 1 && j == 10) || (i == 1 && j == 15) ||
					(i == 5 && j == 7) || (i == 5 && j == 14)) {
					mapSize[gridY][j] = '#';
				}


			}

		}


	}
	for (size_t k = 0; k < Objects.size(); k++) {
		if (Doors* door = dynamic_cast<Doors*>(Objects.at(k))) {
			mapSize[trainOffset + door->getY()][door->getX()] = door->getSymbol();
		}
	}
}

	//////////////////roooms////////////////////////
	else if (carriageRoom == 2) {
		for (int i = 0; i < 7; i++) {

			for (int j = 0; j < 12; j++) {
				int trainOffset = 3;
				int gridY = trainOffset + i;
				//boundary
				if ((j == 0 && i == 0) || (j == 11 && i == 0) || (i == 6 && j == 0) || (j == 11 && i == 6)) {
					mapSize[gridY][j] = '+';
				}
				else if (i == 6 && j == 2) {
					mapSize[gridY][j] = '_';
				}
				else if (i == 0 || i == 6) {
					mapSize[gridY][j] = '=';
				}
				else if (j == 0 || j == 11) {
					mapSize[gridY][j] = '|';
				}
				else {
					mapSize[gridY][j] = ' ';
				}

				if (carriageNum == 3) {
					if (i == 1 && j == 5) {
						mapSize[gridY][j] = '^';
					}
					if (i == 1 && j == 9) {
						mapSize[gridY][j] = '~';
					}
					if (i == 5 && j == 9) {
						mapSize[gridY][j] = 'W';
					}
				}
			}
		}


	}
}

void Map::printSidebar(int carriageNum, int carriageRoom, bool uiActive, const std::string uiBuffer[13]) const {
	std::string leftPanelPadding = "                                  ";
	std::cout << leftPanelPadding << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";
	std::cout << leftPanelPadding << "|                 |    |                 |\n";
	std::cout << leftPanelPadding << "|   CARRIAGE " << carriageNum << "    |    |     ROOM   " << carriageRoom << "    |\n";
	std::cout << leftPanelPadding << "|                 |    |                 |\n";
	std::cout << leftPanelPadding << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";

	for (int i = 0; i < 13; i++) {
		std::string lineBuffer = "";
		if (i == 2) {
			lineBuffer += "   [ CONTROLS ]                   ";
		}
		else if (i == 3) {
			lineBuffer += "   WASD : Move Player             ";
		}
		else if (i == 4) {
			lineBuffer += "   F    : Interact / Use Object   ";
		}
		else lineBuffer += leftPanelPadding;

		for (int j = 0; j < 24; j++) {
			lineBuffer += mapSize[i][j];
			lineBuffer += ' ';
		}
		if (uiActive) {
			lineBuffer += uiBuffer[i]; 
		}
		else {
			lineBuffer += "                                      ";
		}

		std::cout << lineBuffer << "\n";
	}
}

void Map::printMap() const {

	for (int i = 0; i < 13; i++) {

		for (int j = 0; j < 24; j++) {
			std::cout << mapSize[i][j] << " ";
		}	
		std::cout << "\n";
	}
}

//void Map::printCarrIndicator() const {
//	std::cout << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";
//	std::cout << "|                 |    |                 |\n";
//	std::cout << "|   CARRIAGE " << carriageNum << "    |    |     ROOM   " << carriageRoom << "    |\n";
//	std::cout << "|                 |    |                 |\n";
//	std::cout << "+-- -- -- -- -- --+    +-- -- -- -- -- --+\n";
//
//}
void Map::updateMap(int x, int y, char symbol) {
	if (x > 0 && x < 24 && y > 2 && y < 10) {
		mapSize[y][x] = symbol;
	}	
}

bool Map::validMove(int x, int y) {	
	if (x > 0 && x < 24 && y > 2 && y < 10) {
		char tile = mapSize[y][x];
		if (tile == '=' || tile == '|' || tile == '+' || tile == '['
			|| tile == ']' || tile == '@' || tile == '#' || tile == '?' ||
			tile == '&' || tile == '^' || tile == '~' || tile == 'A') {
			return false;
		}
		return true;
	}
	return false;
}

vector<InteractiveObject*> Map::getObjects() {
	return Objects;
}
void Map::clearObjects() {
	Objects.clear();
}
void Map::setObjects(InteractiveObject* object) {
	Objects.push_back(object);
}
bool Map::getOffMap()
{
	return offMap;
}
void Map::setOffMap(bool OffMap)
{
	offMap = OffMap;
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
