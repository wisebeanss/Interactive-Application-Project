#include "Doors.h"
#include "Timer.H"
#include <iostream>
#include <string>
using namespace std;


Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id, false)
{
	line = lines;
	setX(x);
	setY(y);
	setRoomID(id);
	setSymbol('D');
	question = 1;
	attempts = 0;
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

	if (roomID == 1)
	{
		if (question == 1)
		{
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter the time as HHMMSS (e.g., 115012): ";
			cin >> answerT1;
			attempts++;

			if (answerT1 == 115012)
			{
				cout << "\nThe clock begins ticking...\n";
				cout << "11:50...\n";
				cout << "11:51...\n";
				cout << "You stare at its hands. The time feels familiar, yet you cannot recall why.\n";
				cout << "You can now solve Puzzle 2.\n";
				question = 2;
				attempts = 0;
				return;
			}
			else
			{
				cout << "\nThat doesn't seem right.\n";
			
				Timer& t = getGameMap().getTimerObject();

				cout << "Before: " << t.getMinutes() << "m" << t.getSeconds() << "s\n";

				t.decreaseTime(120);
				getGameMap().timerSeconds = t.getMinutes() * 60 + t.getSeconds();

				cout << "After:  " << t.getMinutes() << "m" << t.getSeconds() << "s\n";

				if (attempts == 3)
				{
					cout << "Remember Clock 4 is 5 mins faster!\n";
					attempts -= 1;
				}
				return;
			}
		}

		if (question == 2)
		{
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter which mirror is correct (A/B/C): ";
			cin >> answerT2;
			attempts++;

			answerT2 = toupper(answerT2);
			if (answerT2 == 'C')
			{
				cout << "\r" << string(80, ' ') << "\r";
				cout << "The mirrors go still.\n";
				cout << "Your reflection looks directly at you.\n";
				cout << "You know the truth.\n";
				cout << "Room 2 unlocked!\n";
				changeUnlockedState(true);
				question = 1;
				attempts = 0;
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You step through the door into Carriage 2.\n";
				return;
			}
			else
			{
				cout << "\nThat mirror lies. Think again.\n";
				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";

				if (attempts >= 3)
				{
					cout << " Hint: The reflection should match you.\n";
				}
				return;
			}
		}

		if (question == 3)
		{
			return;
		}
	}

	if (roomID == 2)
	{
		if (question == 1)
		{
			cout << "\r" << string(80, ' ') << "\r";
			cout << "[Room 2] Answer the riddle to unlock the door.\n\n";

		
			cout << "Collect the photo, get the notes and make arrange\n";
			cout << "Enter your answer: ";

			string answer;
			cin >> answer;

			if (answer == "1243") 
			{
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You arrange it in the correct order.\n";
				cout << "The Strong. The Smart. The Perfect. The Successful.\n";
				cout << "All the things you thought you had to be.\n";
				cout << "DID YOU?\n";
				changeUnlockedState(true);
				question = 2;
				cout << "You step through the unlocked door...\n";
				return;
			}

			
			cout << " Wrong arrange.\n";
			Timer& t = getGameMap().getTimerObject();
			t.decreaseTime(120);
			getGameMap().timerSeconds = t.getMinutes() * 60 + t.getSeconds();
			cout << "Time remaining: " << t.getMinutes() << "m " << t.getSeconds() << "s\n";
			return;
		}

		if (question == 2)
		{
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Room 2 complete! Moving forward...\n";
			return;
		}

		return;
	}
}