#include "Game.h"
Game::Game() {
	
}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.printMap();
}
void Game::Run() {
	while (true) {
		char letter = _getch();
		player.move(letter);
		map.updateMap(player.getY(), player.getX(), player.getSymbol());
		map.printMap();
	}
}
void Game::End() {

}
