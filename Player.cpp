#include "Player.h"
#include "Doors.h"

Player::Player() : GameObject(2, 6, 'P') {
	setInteract(false);
	Inventory.fill(nullptr);
	discarding = false;
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
std::string Player::getInvItemSlot(int index) const {
	InteractiveObject* obj = Inventory.at(index);
	return (obj == nullptr) ? "Empty" : obj->getName() + to_string(obj->getId());
}
bool Player::Equip(InteractiveObject* object) {
	for (int objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		if (Inventory.at(objIdx) == nullptr) {
			//Reminder to self, when inventory is full, make sure to ask user to discard
			Inventory.at(objIdx) = object;
			return true;
			break;
		}
	}
	return false;
}
void Player::ClearInv() {
	for (int objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		if (Inventory.at(objIdx) != nullptr) {
			delete Inventory.at(objIdx);
			Inventory.at(objIdx) = nullptr;
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
		for (size_t i = 0; i < map.getObjects().size(); i++) {
			InteractiveObject* obj = map.getObjects()[i];
			if (obj->getX() == getX() && obj->getY() == getY()) {
				if (Equip(obj)) {
					map.removeObject(obj);
				}
				break;
			}
		}
		setInteract(false);
		system("cls");
		map.setMapRendered(true);
	}
	else if (symbol == 'l') { /////////////////////////debugging?///////
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
	else if (symbol >= '1' && symbol <= '6') {
		int InvSlotIdx = static_cast<int>(symbol - '1');
		if (Inventory.at(InvSlotIdx) != nullptr) {
			Inventory.at(InvSlotIdx)->use();
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

		if (map.mapSize[newY][newX] == 'D') {
			//door next carriage
			for (InteractiveObject* obj : map.getObjects())
			{
				Doors* door = dynamic_cast<Doors*>(obj);

				if (door != nullptr &&
					door->getRoomID() == map.getCarriage() &&
					getX() == door->getX() &&
					getY() == door->getY() &&
					door->isUnlocked())
				{
					map.nextCarriage();
					ClearInv();
					setX(2);
					setY(6);	 

					map.buildMap();
					break;
				}
			}
		}
	}
}
void Player::setInteract(bool Interact)
{
	interact = Interact;
}
bool Player::getInteract() const
{
	return interact;
}