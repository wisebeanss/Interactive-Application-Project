#include "Doors.h"
Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id, false)
{
	line = lines;
	setX(x);
	setY(y);
	setRoomID(id);
	question = 1;
}
Doors::~Doors()
{

}
void Doors::setLine(string lines)
{
	line = lines;
}
void Doors::setRoomID(bool id)
{
	roomID = id;
}
void Doors::use()
{
	int answerT1;
	int attempts = 0;
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
				cout << "The time feels strangely familiar.\n";
				question = 2;
				return;
			}
			else {
				cout << "\nThat doesn't seem right.\n";
					
				if (attempts == 3) {
					std::cout << "= !Remember the clock is 5 mins slower!=\n";
					attempts -= 1;
				}
			}

			}

	if (question == 2) {
		cout << "\r" << string(80, ' ') << "\r";
		cout << "Enter which mirror is correct \n";
		cin >> answerT2;
		attempts++;
		if (answerT2 == 'C') {
			cout << "\r" << string(80, ' ') << "\r";
			cout << "The mirrors go still\n";
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Your reflection looks directly at you\n";
			cout << "\r" << string(80, ' ') << "\r";
			cout << "You know the truth.\n";
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Room 2 unlocked!\n";
			question = 3;
			return;
		}
		else {
			cout << "\n That mirror lies. Think again.\n";
			if (attempts >= 3)
			{
				cout << " Hint: The reflection should match you.\n";
			}
			cout << "Your answer: ";
		}
		
		}
	}
}