#include "Game.h"

Game::Game() {

}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.updateMap(player.getX(), player.getY(), player.getSymbol());
	map.printSidebar(1, 1, false);
	//map.printMap();
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
		//timer
		map.updateTimer();
		getGameMap().updateTimer();
		//mapping
	
		map.updateFrame(); //upd map env frame
		map.buildMap();
		//map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());

		std::string uiBuffer[15];
		bool isUIActive = false;
		std::string statusMsg = "";

		// If player is interacting with mirror object
		InteractiveObject* obj = player.getNearbyObject(map);
		if (obj != nullptr && obj->getUIActive()) {
			isUIActive = true;
			obj->getUIBuffer(uiBuffer); // Fills 13-line array
		}
		else { statusMsg = "Click 'F' to Interact"; }

		// Render map and UI simultaneously
		map.resetCursorPosition();
		map.printSidebar(map.getCarriage(), map.getRoom(), isUIActive, uiBuffer);

		//map.printMap();

		puzzle.ROOMS(map.getCarriage(), map);

		auto frameEnd = std::chrono::high_resolution_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
		if (elapsedTime < frameBudget) {
			std::this_thread::sleep_for(frameBudget - elapsedTime);
		}
	}
}
void Game::End() {

}