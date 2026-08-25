#include "Game.h"

Game::Game() : player(map){
}
Game::~Game() {

}
void Game::Init() {
	map.buildMap();
	map.updateMap(player.getX(), player.getY(), player.getSymbol());
	//map.printMap();
	std::string defaultBuffer[13];
	for (int i = 0; i < 13; i++) defaultBuffer[i] = "                                   ";
	map.printSidebar(1, 1, false, player, defaultBuffer);
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
			player.HandleInput(letter);
		}
		//timer
		map.updateTimer();
		getGameMap().updateTimer();
		//mapping

		map.updateFrame(); //upd map env frame
		map.buildMap();
		//map.updateMap(oldX, oldY, ' ');
		map.updateMap(player.getX(), player.getY(), player.getSymbol());

		std::string uiBuffer[13];
		for (int i = 0; i < 13; i++) {
			uiBuffer[i] = "                                   "; // 35 spaces
		}
		bool isUIActive = false;
		std::string statusMsg = "";

		// If player is interacting with mirror object
		InteractiveObject* activeObj = nullptr;
		InteractiveObject* nearObj = player.getNearbyObject();
		if (nearObj != nullptr && nearObj->getUIActive()) {
			activeObj = nearObj;
			/*		isUIActive = true;
					obj->getUIBuffer(uiBuffer); */
		}
		if (activeObj == nullptr) {
			for (int i = 0; i < 7; i++) {
				InteractiveObject* invItem = player.getInventoryItem(i);
				if (invItem != nullptr && invItem->getUIActive()) {
					activeObj = invItem;
					break;
				}
			}
		} 
		if (activeObj != nullptr && activeObj->getUIActive()) {
			isUIActive = true;
			activeObj->getUIBuffer(uiBuffer);
		}
		// Render map and UI simultaneously
		map.resetCursorPosition();
		map.printSidebar(map.getCarriage(), map.getRoom(), isUIActive, player, uiBuffer);

		//map.printMap();

		puzzle.Carriages(map.getCarriage(), map.getRoom(), map);

		auto frameEnd = std::chrono::high_resolution_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
		if (elapsedTime < frameBudget) {
			std::this_thread::sleep_for(frameBudget - elapsedTime);
		}
	}


}
void Game::End() {

}