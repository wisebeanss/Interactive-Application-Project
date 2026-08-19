#include "Game.h"
Game::Game() {
	
}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.updateMap(player.getX(), player.getY(), player.getSymbol());
	map.printCarrIndicator();
	map.printMap();
}
void Game::Run() {
	Puzzle puzzle;
	while (true) {
		char letter = _getch();
		int oldY = player.getY();
		int oldX = player.getX();
		system("cls");
		player.move(letter, map);		
		map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());
		map.printCarrIndicator();
		map.printMap();
		player.HandleInput(letter, map);
		switch (map.getCarriage()) {
		case 1:
			puzzle.ROOM1(1, map);
			break;
		case 2:
			puzzle.ROOM2(1, map);
			break;
		case 3:
			puzzle.ROOM3(1, map);
			break;
		case 4:
			puzzle.ROOM4(1, map);
			break;
		case 5:
			puzzle.ROOM5(1, map);
			break;
		case 6:
			puzzle.ROOM6(1, map);
			break;
		}
	}
}
void Game::End() {

}
