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
		int oldY = player.getY();
		int oldX = player.getX();
		player.move(letter);
		map.updateMap(oldY, oldX, ' ');
		map.updateMap(player.getY(), player.getX(), player.getSymbol());
		system("cls");
		map.printMap();
	}
}
void Game::End() {

}
