#include "Game.h"
Game::Game() {
	
}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.updateMap(player.getX(), player.getY(), player.getSymbol());
	map.printMap();
}
void Game::Run() {
	while (true) {
		char letter = _getch();
		int oldY = player.getY();
		int oldX = player.getX();
		player.move(letter, 22, 5);
		map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());
		system("cls");
		map.printMap();
	}
}
void Game::End() {

}
