#include "Doors.h"
Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id)
{
	line = lines;
	setX(x);
	setY(y);
}
Doors::~Doors()
{

}
void Doors::setLine(string lines)
{
	line = lines;
}
void Doors::use()
{
	cout << line;
	int answerT1;
	int attempts = 0;
	char answerT2 = ' ';

	if (roomID == 1) {
		if (question == 1) {
			cout << "Enter the time as HHMMSS (e.g., 115012): ";
			cin >> answerT1;
			attempts++;

			while (true) {
				if (answerT1 == 115012) {
					cout << "\nThe clock begins ticking...\n";
					cout << "11:50...\n";
					cout << "11:51...\n";
					cout << "The time feels strangely familiar.\n";
					cout << "✓ Room 1 unlocked!\n";
					question = 2;
					return;
				}
				else {
					cout << "\nThat doesn't seem right.\n";
					
					if (attempts == 3) {
						std::cout << "= !Remember the clock is 5 mins slower!=\n";
					}
				}

			}


		
		}
	}
}