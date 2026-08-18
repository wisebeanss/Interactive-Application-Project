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
	while (true) {
		char letter = _getch();
		int oldY = player.getY();
		int oldX = player.getX();
		system("cls");
		player.HandleInput(letter, map);
		map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());
		map.printMap();
	}
}
void Game::End() {

}
