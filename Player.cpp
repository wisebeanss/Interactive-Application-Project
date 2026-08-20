#include "Player.h"


Player::Player() : GameObject(2, 6, 'P') {
	setInteract(false);
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
void Player::Equip(InteractiveObject* object) {
	Inventory.push_back(object);
}
void Player::Discard(InteractiveObject* object) {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		if (Inventory[objIdx] == object) {
			delete Inventory[objIdx];
			Inventory.erase(Inventory.begin() + objIdx);
			break;
		}
	}
}
InteractiveObject* Player::getNearbyObject(Map& map) {
	for (int i = 0; i < map.getObjects().size(); i++) {
		int objX = map.getObjects()[i]->getX();
		int objY = map.getObjects()[i]->getY();
		if ((objX == getX() && objY == getY() + 1) ||
			(objX == getX() && objY == getY() - 1) ||
			(objX == getX() + 1 && objY == getY()) ||
			(objX == getX() - 1 && objY == getY()))
		{
			return map.getObjects()[i];
		}
	}
	return nullptr;
}
void Player::HandleInput(char symbol, Map &map) {
	//movement
	if (symbol == 'w' || symbol == 'a' || symbol == 's' || symbol == 'd') {
		for (size_t i = 0; i < map.getObjects().size(); i++) {

			InteractiveObject* obj = map.getObjects()[i];
			if (obj != nullptr && obj->getUIActive()) {
				obj->enableUI(); // Toggles uiActive back to false webn they walk
			}
		}

		move(symbol, map);
		setInteract(false);
		system("cls");
		map.setMapRendered(true);
		
	}
	if (symbol == 'e') {
		if (Inventory.empty()) {
			cout << "\r" << string(80, ' ') << "\r";
			std::cout << "Nothing in Inventory" << std::endl;
		}
		else {
			for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
				cout << "\r" << string(80, ' ') << "\r";
				std::cout << Inventory[objIdx]->getName() << " " << Inventory[objIdx]->getId();
			}
		}

	}

	else if (symbol == 'l') {
		map.nextCarriage();
		map.buildMap();
	}
	else if (symbol == 'k') {
		map.nextRoom();
		map.buildMap();
	}	
	else if (symbol == 'f') {
		InteractiveObject* nearbyObject = getNearbyObject(map);
		if (nearbyObject != nullptr) {
			setInteract(true);
			nearbyObject->use();
			map.setMapRendered(false);
		}
	}
}
void Player::move(char movement, Map &map)
{
	int newX = getX();
	int newY = getY();
	switch (movement) {
	case 'w':
		newY -= 1;
		break;
	case 'a':
		newX -= 1;
		break;
	case 's':
		newY += 1;
		break;
	case 'd':
		newX += 1;
		break;
	default:
		break;
	}
	map.buildMap();
	// Only update if valid
	if (map.validMove(newX, newY)) {
		setX(newX);
		setY(newY);
	}
}
void Player::setInteract(bool Interact)
{
	interact = Interact;
}
bool Player::getInteract()
{
	return interact;
}