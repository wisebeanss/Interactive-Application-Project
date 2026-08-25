#include "Doors.h"
#include "Timer.H"
#include <iostream>
#include <string>
#include <cctype>
#include "Dialogue.h"
using namespace std;


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
				
				return;
			}
			else
			{
				dialogue.show({
				"That doesn't seem right..",
				"Two minutes have been deducted.",
				"Press Enter to continue.",


					});
				
				cin.ignore();
				cin.get();

				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);
				
				return;
			}
		}

		if (question == 2)
		{
			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter which mirror is correct (A/B/C): ";
			cin >> answerT2;
		

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
			cout << "1.	The last letter was written after I stopped expecting an answer.\n";
			cout << "Tell me which letter is the last one \n";
			cout << "Enter your answer: ";
			cin >> answerT2;
			if (answerT2 == 'D') {
				cout << "\r" << string(80, ' ') << "\r";
				cout << "Letters lie scattered across the table, written one after another as hope slowly faded.\n";
				cout << "Two notes are pinned to the wall:\n";
				cout << "All the things you thought you had to be.\n";
				cout << "\"Which one are you ? \"\n";
				cout << "\nPress Enter to continue...";
				cin.ignore();
				cin.get();

				system("cls");
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
				
				

			}
			return;
		}

		if (question == 2) {

		}

			return;
	
	}
	if (roomID == 6) {
		if (question == 1) {
			cout << "\r" << string(80, ' ') << "\r";
			cout << "When the train finally stops, the flames die out, and silence swallows everything around you — what is the very last sound you hear ?\n";
			cout << "1. Nothing. The world has been muted.\n";
			cout << "2. A name — you can't quite place whose, but your chest tightens.\n";
			cout << "3. Your own heartbeat — steady, clear, present.\n";
			cout << "Choose 1/2/3:   ";
			cin >> answerT1;
			if (answerT1==1) {
				cout << "You step through the door, expecting freedom.\n";
				cout << "Instead, you find yourself back in Carriage 1.\n";
				cout << "The furnace erupts in violet flames as the train accelerates into the darkness.\n";
				cout << "You turn back—but the door is gone.\n";
				cout << "The notes, photographs, and keys have disappeared from your pockets.\n";
				cout << "You couldn't face what happened at 11:35.\n";
				cout << "The clock ticks backward.\n";
				cout << "Here, you never have to remember.\n";
				cout << "You never have to mourn.\n";
				cout << "You never have to admit they're gone.\n";
				cout << "You run toward Carriage 2.\n";
				cout << "[The loop begins again.]\n";
				cout << "MISSION COMPLETE\n";
				return;

			}

			else if (answerT1==2) {
				cout << "You step through the door, Your reflection stands waiting on the other side.\n";
				cout << "'You know what happened.'\n";
				cout << "This time, you don't deny it, You don't run either.\n";
				cout << "You simply stare at yourself.\n";
				cout << "The train begins to slow,The purple flames shrink, but they do not disappear.\n";
				cout << "You couldn't face what happened at 11:35.\n";
				cout << "'I accept it.'\n";
				cout << "The reflection smiles.\n";
				cout << "The door behind you opens,Beyond it is a long, empty tunnel.\n";
				cout << "You step forward.\n";
				cout << "But the train remains behind you, still burning quietly in the darkness.\n";
				cout << "[You have accepted the truth—but you haven't let go.]\n";
				cout << "MISSION COMPLETE\n";
				return;
			}
			else if (answerT1==3) {
				cout << "You ignore the false exits and walk toward the furnace.\n";
				cout << "'The dark-purple flames roar, burning with every suppressed tear, unanswered question, and buried memory.'\n";
				cout << "You do not turn away.\n";
				cout << "You reach through the flames and grasp the EMERGENCY BRAKE.\n";
				cout << "You pull.\n";
				cout << "	The train screeches violently before finally coming to a halt. The furnace fades to embers.\n";
				cout << "Silence fills the carriage.\n";
				cout << "The reflection smiles.\n";
				cout << "You open the door.\n";
				cout << "There is no abyss—only a quiet tunnel and a small circle of daylight ahead.\n";
				cout << "You take a breath and walk toward the light.\n";
				cout << "'For the first time, you move forward.'\n";
				cout << "[The train will never run again..]\n";
				cout << "MISSION COMPLETE\n";
				return;
			}
			return;

		}
	}
}

