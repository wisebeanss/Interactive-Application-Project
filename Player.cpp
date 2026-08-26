#include "Player.h"
#include "Doors.h"

Player::Player(Map &map) : GameObject(2, 6, 'P') , map(map){
	setInteract(false);
	Inventory.fill(nullptr);
}
Player::~Player() {
	for (size_t objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		delete Inventory[objIdx];
		Inventory[objIdx] = nullptr;
	}
}
std::string Player::getInvItemName(int index) const {
	InteractiveObject* obj = Inventory.at(index);
	return (obj == nullptr) ? "Empty" : obj->getName() + to_string(obj->getId());
}
InteractiveObject* Player::getInventoryItem(int index) const {
	if (index >= 0 && index < 7) return Inventory[index];
	return nullptr;
}
bool Player::hasItem(string name) const {
	for (int i = 0; i < 7; i++) {
		InteractiveObject* obj = Inventory[i];
		if (obj != nullptr && obj->getName() == name) {
			return true;
		}
	}
	return false;
}
bool Player::Equip(InteractiveObject* object) {
	for (int objIdx = 0; objIdx < Inventory.size(); objIdx++) {
		if (Inventory.at(objIdx) == nullptr) {
			Inventory.at(objIdx) = object;
			if (object->getName() == "Photo Piece")
			{
				for (InteractiveObject* itm : map.getObjects())
				{
					if (itm->getName() == "Suitcase")
					{
						Suitcase* suitcase = dynamic_cast<Suitcase*>(itm);
						suitcase->collectPhoto();
					}
				}
			}
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
InteractiveObject* Player::getNearbyObject() {
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
void Player::HandleInput(char symbol) {
	//movement
	if (symbol == 'w' || symbol == 'a' || symbol == 's' || symbol == 'd') {
		for (size_t i = 0; i < map.getObjects().size(); i++) {
			InteractiveObject* obj = map.getObjects()[i];
			if (obj != nullptr && obj->getUIActive()) {
				obj->disableUI(); // Toggles uiActive back to false webn they walk
			}
		}
		for (size_t i = 0; i < Inventory.size(); i++) {
			if (Inventory[i] != nullptr) {
				Inventory[i]->disableUI();
			}
		}
		move(symbol);
		for (size_t i = 0; i < map.getObjects().size(); i++) {
			InteractiveObject* obj = map.getObjects()[i];
			if (obj != nullptr && obj->getX() == getX() && obj->getY() == getY()) {
				obj->disableUI(); // Ensure UI is OFF when entering inventory
				Equip(obj);
				map.removeObject(obj);
				break;
			}
			if (map.mapSize[getY()][getX()] == '_') {
				cout << map.getRoom();
				if (map.getRoom() == 1) {
					map.nextRoom();
					setX(2);
					setY(8);
					break;
				}
				else {
					map.prevRoom();
					setX(21);
					setY(4);
					break;
				}
				
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
		InteractiveObject* nearbyObject = getNearbyObject();
		if (nearbyObject != nullptr) {
			setInteract(true);
			nearbyObject->use();
			map.setMapRendered(false);
		}
	}
	else if (symbol >= '1' && symbol <= '7') {
		int InvSlotIdx = static_cast<int>(symbol - '1');
		for (size_t i = 0; i < map.getObjects().size(); i++) {
			if (map.getObjects()[i] != nullptr) {
				map.getObjects()[i]->disableUI();
			}
		}
		for (size_t i = 0; i < Inventory.size(); i++) {
			if (Inventory[i] != nullptr && static_cast<int>(i) != InvSlotIdx) {
				Inventory[i]->disableUI();
			}
		}
		if (InvSlotIdx < static_cast<int>(Inventory.size()) && Inventory.at(InvSlotIdx) != nullptr) {
			InteractiveObject* selectedItem = Inventory.at(InvSlotIdx);
			if (selectedItem->getUIActive()) {
				selectedItem->disableUI();
			}
			else {
				selectedItem->use(); 
			}
		}
	}
}
void Player::move(char movement)
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