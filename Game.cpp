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
	const std::chrono::milliseconds frameBudget(33);

	while (true) {
		auto frameStart = std::chrono::high_resolution_clock::now();

		int oldY = player.getY();
		int oldX = player.getX();

		if (_kbhit()) {
			char letter = _getch();
			player.HandleInput(letter, map);
		}
		if (player.getNearbyObject(map) != nullptr) {
			cout << "Press F to Interact";
		}
		else {
			cout << "\r" << string(80, ' ') << "\r";
		}
		//mapping
		map.updateFrame(); //upd map env frame
		map.buildMap();

		//map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());

		map.resetCursorPosition();

		map.printCarrIndicator();
		map.printMap();

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

		auto frameEnd = std::chrono::high_resolution_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
		if (elapsedTime < frameBudget) {
			std::this_thread::sleep_for(frameBudget - elapsedTime);
		}
	}
}
void Game::End() {

}
