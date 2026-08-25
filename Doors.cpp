#include "Doors.h"
#include "Timer.H"
#include <iostream>
#include <string>
#include <cctype>
#include "Dialogue.h"
using namespace std;


Doors::Doors(string lines, int x, int y, int id, int dID) : InteractiveObject("Doors", id, false)
{
	line = lines;
	setX(x);
	setY(y);
	setRoomID(id);
	setDoorID(dID);
	setSymbol('D');
	question = 1;
	attempts = 0;
	changeUnlockedState(false);
}

void Doors::setDoorID(int id)
{
	doorID = id;
}

int Doors::getDoorID() const
{
	return doorID;
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
	Dialogue dialogue;
	int answerT1;
	char answerT2 = ' ';
	string answerT3;

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
				dialogue.show({
				"The clock begins ticking...",
				"11:50...",
				"11:51...",
				"You stare at its hands.",
				"The time feels familiar,",
				"yet you cannot recall why.",
				"You can now solve Puzzle 2.",
				"Press Enter to continue...",
					});
				cin.ignore();
				cin.get();

				system("cls");
				question = 2;
				attempts = 0;
				return;
			}
			else
			{
				dialogue.show({
				"That doesn't seem right..",
				"Two minutes have been deducted.",
				"Press Enter to continue.",


					});
				Timer& t = getGameMap().getTimerObject();

				cin.ignore();
				cin.get();

				system("cls");

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
				cout << "You look away. \n";
				cout << "\"Stop pretending you don't.\"\n";
				cout << "The door unlocks.";
				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");
				changeUnlockedState(true);
				question = 1;
				attempts = 0;
				cout << "\r" << string(80, ' ') << "\r";
				return;
			}
			else
			{
				cout << "\nThat mirror lies. Think again.\n";
				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";
				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");

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
			cout << "What is the arrangement?\n";
			cout << "Enter your answer: ";
			cin >> answerT1;
			
		

			if (answerT1 == 1243 )
			{
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You arrange it in the correct order.\n";
				cout << "The Strong. The Smart. The Perfect. The Successful.\n";
				cout << "All the things you thought you had to be.\n";
				cout << "\"Which one are you ? \"\n";
				cout << "You don't answer.\n";
				cout << "The poster go dark.\n";
				cout << "The door clicks.\n";
				
				changeUnlockedState(true);
				question = 2;
			
				return;
			}

			else {
				cout << "Wrong arrangement.\n";
				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";
				cout << "\nPress Enter to continue.4";
				cin.ignore();
				cin.get();

				system("cls");
				return;
			}
		}
		if (question == 2)
		{
		}

		return;
	}

	if (roomID == 3)
	{
		if (question == 1)
		{
			cout << "You should pick up.......\n";
			cin >> answerT3;

			//uppercase
			for (char& c : answerT3)
			{
				c = toupper(c);
			}

			if (answerT3 == "WATCH")
			{
				cout << "\nYou pick up the watch.\n";
				cout << "11:35.\n";
				cout << "The same time again. \n";
				cout << "You stare at it, remembering the blame you carried all this time. \n";
				cout << "\"It happened at 11:35...\"\n";
				cout << "\"But you weren't there.\"\n";
				cout << "The memory begins to crack.\n";
				cout << "Maybe it was your fault. \n";
				cout << "The door unlocks.  \n";

				changeUnlockedState(true);

				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");

				question = 2;
				return;
			}
			else
			{
				cout << "\nWrong answer.\n";

				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";

				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");
				return;
			}
		}

		if (question == 2)
		{
		}

		return;

	}

	if (roomID == 4)
	{
		if (question == 1)
		{

			cout << "\r" << string(80, ' ') << "\r";
			cout << "What is the arrangement?\n";
			cout << "Enter your answer: ";
			cin >> answerT1;



			if (answerT1 == 1243)
			{
				cout << "\r" << string(80, ' ') << "\r";
				cout << "You arrange the memories in order.\n";
				cout << "Childhood. Last Summer.Photograph.First Train Ride. \n";
				cout << "You stare at the words.\n";
				cout << "Something feels wrong. \n";
				cout << "You read the diary page again.\n";
				cout << "\"I don't remember writing one of the lines.\" \n";
				cout << "You recognize the handwriting.\n";
				cout << "\"Then who wrote it ? \" \n";
				cout << "A faint memory surfaces. \n";
				cout << "Someone sitting beside you.\n A train window.\nTheir voice. \n";
				cout << "A voice whispers in your ears\n";
				cout << "\"You promised you wouldn't forget.\"\n";
				cout << "The door unlocks. \n";

				changeUnlockedState(true);
				question = 2;

				return;
			}
			else {
				cout << "Wrong arrangement.\n";
				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";
				cout << "\nPress Enter to continue.4";
				cin.ignore();
				cin.get();

				system("cls");
				return;
			}

			if (question == 2)
			{
			}

			return;


		}
	}
	if (roomID == 5) {
		if (question == 1) {
			cout << "\r" << string(80, ' ') << "\r";
			cout << "TAKE NOTE:\n";
			cout << "1. The last letter was written after I stopped expecting an answer.\n";
			cout << "Tell me which letter is the last one \n";
			cin >> answerT1;
			if (answerT1 == 3 ) {
				cout << "\r" << string(80, ' ') << "\r";
				cout << "Letters lie scattered across the table, written one after another as hope slowly faded.\n";
				cout << "Two notes are pinned to the wall:\n";
				cout << "All the things you thought you had to be.\n";
				cout << "\"door unlocks. \"\n";
				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				changeUnlockedState(true);
				system("cls");
				attempts = 0;
				question = 2;
				return;
			}
			else{
				cout << "\nWrong answer.\n";

				getGameMap().timer.decreaseTime(2 * 60);
				cout << "2 minutes have been deducted!\n";

				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");
				return;
				if (attempts >= 3) {
					cout << "TAKE NOTE: \n";
					cout << "I stopped calling before i  stopped writing.\n ";
					attempts -= 1;

				}
				return;

			}
		}

		if (question == 2) {

		}

			return;
	
	}
	if (roomID == 6) {
		if (doorID == 61)
		{
			// BAD ENDING
			cout << "You chose the wrong door.\n";
			cout << "The train continues endlessly...\n";
		}
		else if (doorID == 62)
		{
			// NEUTRAL ENDING
			cout << "You pull the emergency brake.\n";
			cout << "The train finally stops.\n";
		}
		else if (doorID == 63)
		{
			// TRUE ENDING
			cout << "You finally accept the truth.\n";
			cout << "The doors open.\n";
		}

		return;

	}
}

