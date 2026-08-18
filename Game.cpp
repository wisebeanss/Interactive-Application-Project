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
	char letter = _getch();
	player.move(letter);
	map.updateMap(player.getX(), player.getY(), 'P');
	map.printMap();
}
void Game::End() {

}