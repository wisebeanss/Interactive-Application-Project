#include "Doors.h"
Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id, false)
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
			while (true) 
			{
				cin >> answerT1;
				attempts++;


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

	if (question == 2) {
		cout << "Enter which mirror is correct/n";
			while (true) {
					cin >> answerT2;
					attempts++;
				}
			if (answerT2 == 'C ') {
				cout << "The mirrors go still\n";
				cout << "Your reflection looks directly at you\n";
				cout << "You know the truth.\n";
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
}