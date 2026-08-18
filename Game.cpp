#include "Game.h"
Game::Game() {
	
}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.printCarrIndicator();
	map.printMap();
}
void Game::Run() {
	while (true) {
		char letter = _getch();
		int oldY = player.getY();
		int oldX = player.getX();
		player.move(letter);
		map.updateMap(oldY, oldX, ' ');
		map.updateMap(player.getY(), player.getX(), player.getSymbol());
		map.printMap();
	}
}
void Game::End() {

}
