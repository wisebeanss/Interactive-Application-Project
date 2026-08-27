#include "Game.h"
#include "MainMenu.h"
#include"Sound.h"
Sound background;
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
	map.timer.resetTimer();
	Puzzle puzzle;
	/*background.Background();*/
	const std::chrono::milliseconds frameBudget(33);

	while (true) {


		auto frameStart = std::chrono::high_resolution_clock::now();

		if (map.timer.isTimeUp()) {
			MainMenu menu;
			int choice = menu.ShowGameOverMenu(player);

			if (choice == 1) {
				system("cls");
				map.timer.resetTimer();
				player.setX(2);         
				player.setY(6);         
				player.ClearInv();
				map.buildMap();
				map.resetMap(player);
				continue;              
			}
			else if (choice == 2) {
	
				menu.Show(player);
				return;         
			}
			else if (choice == 3) {

				exit(0);
			}
		}
		if (_kbhit()) {
			char letter = _getch();
			//Check for Esc Key
			if (letter == 27) {
				MainMenu pauseMenu;
				int choice = pauseMenu.ShowPauseMenu();
				switch (choice) {
				case 1:
					continue;
				case 2:
					background.StopAll();
					End();
					return;
				case 3:
					background.StopAll();
					background.PlayExit();
					End();
					Sleep(800);
					exit(0);
				}
			}
			else {
				player.HandleInput(letter);
			}
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

		puzzle.ROOMS(map.getCarriage(), map, player);
		if (getGameMap().isEnded()) {
			End();
			return;
		}
		auto frameEnd = std::chrono::high_resolution_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
		if (elapsedTime < frameBudget) {
			std::this_thread::sleep_for(frameBudget - elapsedTime);
		}
	}

}
void Game::End() {
	cout << "Ending Program\n";
}