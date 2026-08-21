#include "Doors.h"
#include "Timer.H"
Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id, false)
{
	line = lines;
	setX(x);
	setY(y);
	setRoomID(id);
	setSymbol('D');
	question = 1;
	changeUnlockedState(false);
}
Doors::~Doors()
{

}
int Doors::getRoomID() const
{
	return roomID;
}
bool Doors::isUnlocked() const {
	return unlocked;
}
void Doors::changeUnlockedState(bool state) {
	unlocked = state;
}
void Doors::setLine(string lines)
{
	line = lines;
}
void Doors::setRoomID(int id)
{
	roomID = id;
}
void Doors::use()
{
	int answerT1;
	char answerT2 = ' ';

	if (roomID == 1) {
		if (question == 1) {
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter the time as HHMMSS (e.g., 115012): ";
			cin >> answerT1;
			attempts++;


			if (answerT1 == 115012) {
				cout << "\nThe clock begins ticking...\n";
				cout << "11:50...\n";
				cout << "11:51...\n";
				cout << "You stare at its hands. The time feels familiar, yet you cannot recall why.\n";
				cout << "You can now solve Puzzle 2.\n";
				question = 2;
				attempts = 0;
				return;
			}
			else {
				cout << "\nThat doesn't seem right.\n";

				if (attempts == 3) {
					std::cout << "Remember Clock 4 is 5 mins faster!\n";
					attempts -= 1;
				}
			}

		}

		if (question == 2) {
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter which mirror is correct \n";
			cin >> answerT2;
			attempts++;
			if (answerT2 == 'C' || answerT2 == 'c') {
				cout << "\r" << string(80, ' ') << "\r";
				cout << "The mirrors go still\n";
				cout << "\r" << string(80, ' ') << "\r";
				cout << "Your reflection looks directly at you\n";
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You know the truth.\n";
				cout << "\r" << string(80, ' ') << "\r";
				cout << "Room 2 unlocked!\n";
				changeUnlockedState(true);
				question = 3;
				attempts = 0;
				return;
			}
			else {
				cout << "\nThat mirror lies. Think again.\n";
				timer.decreaseTime(2 * 60);

				cout << "2 minutes have been deducted!\n";
				if (attempts >= 3)
				{
					cout << " Hint: The reflection should match you.\n";
				}
				
			}

			// Both puzzles solved
			if (question == 3)
			{
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You step through the door into Carriage 2.\n";

			}
		}
	}

	if (roomID == 2) {
		
	}
}