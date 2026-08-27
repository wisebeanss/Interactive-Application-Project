#include "Doors.h"
#include "Timer.h"
#include <iostream>
#include <string>
#include <cctype>
#include "Dialogue.h"
#include <Windows.h>
#include"Sound.h"
using namespace std;
Sound Doorplay;
Doors::Doors(string lines, int x, int y, int id, int dID) : InteractiveObject("Doors", id, false)
{
	line = lines; //object in puzzle
	setX(x);
	setY(y);
	setRoomID(id);
	setDoorID(dID);
	setSymbol('D');
	question = 1;
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

void Doors::clearQuestion(COORD startPos, int lines)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //control cursor

	for (int i = 0; i < lines; i++)
	{
		//cursor on question line
		COORD pos;
		pos.X = startPos.X;
		pos.Y = startPos.Y + i;

		SetConsoleCursorPosition(hConsole, pos);

		cout << string(100, ' ');
	}

	// Return cursor to the original question position
	SetConsoleCursorPosition(hConsole, startPos);
}

void Doors::use()
{
	Dialogue dialogue;
	int answerT1;
	char answerT2 = ' ';
	string answerT3;
	setRoomID(getGameMap().getCarriage());
	if (roomID == 1)
	{
		if (isUnlocked() || question > 2) {
			return;
		}
		Doorplay.PlayKnock();
		if (question == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);//get where the cursor currently is

			COORD questionPos = info.dwCursorPosition; //saves the cursor current position as questionPos

			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter the time as HHMMSS: ";
			cin >> answerT1;

			clearQuestion(questionPos, 1);
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

					}, 42, 10, 35, 18);


				system("cls");
				question = 2;
				return;
			}
			else
			{
				Doorplay.PlayError();
				dialogue.show({
					"That doesn't seem right..",
					"Two minutes have been deducted.",

					}, 42, 10, 35, 18);



				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);


				return;
			}
		}

		if (question == 2)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;

			cout << "\r" << string(80, ' ') << "\r";
			cout << "Enter which mirror is correct (A/B/C): ";
			cin >> answerT2;

			clearQuestion(questionPos, 1);

			answerT2 = toupper(answerT2);
			if (answerT2 == 'C')
			{
				dialogue.show({
				"The mirrors go still.",
				"Your reflection looks directly at you.",
				"You look away.",
				"\"Stop pretending you don't.\"",
				"The door unlocks.",

					}, 42, 10, 35, 18);
				Doorplay.PlayDoor();


				system("cls");
				changeUnlockedState(true);
				question = 1;

				return;
			}
			else
			{
				Doorplay.PlayError();
				dialogue.show({
				"That mirror lies. Think again.",
				"2 minutes have been deducted!",

					}, 42, 10, 35, 18);



				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);

				return;
			}
		}


	}

	if (roomID == 2)
	{
		Doorplay.PlayKnock();
		if (question == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;

			cout << "\r" << string(80, ' ') << "\r";
			cout << "What is the arrangement:";
			cin >> answerT1;

			clearQuestion(questionPos, 1);


			if (answerT1 == 1243)
			{
				dialogue.show({
				"You arrange it in the correct order.",
				"The Strong, Smart, Perfect, Successful.",
				"All the things you thought you had to be.",
				"\"Which one are you?\"",
				"You don't answer.",
				"The door clicks.",
					}, 42, 10, 35, 18);


				system("cls");

				changeUnlockedState(true);
				question = 2;
				Doorplay.PlayDoor();
				return;
			}

			else {
				Doorplay.PlayError();
				dialogue.show({
				"Wrong arrangement.",
				"2 minutes have been deducted!"
					}, 42, 10, 35, 18);


				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);
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
		Doorplay.PlayKnock();
		if (question == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;


			cout << "What is the answer:";
			cin >> answerT3;

			clearQuestion(questionPos, 1);

			//uppercase
			for (char& c : answerT3)
			{
				c = toupper(c);
			}

			if (answerT3 == "WATCH")
			{
				dialogue.show({
				"11:35.",
				"You stare at it",
				"remembering the blame you carried all this time.",
				"\"It happened at 11:35...\"",
				"\"But you weren't there.\"",
				"The memory begins to crack.",
				"Maybe it was your fault. ",
				"The door unlocks.",
					}, 54, 10, 30, 18);

				changeUnlockedState(true);

				Doorplay.PlayDoor();
				system("cls");

				question = 2;
				return;
			}
			else
			{
				Doorplay.PlayError();
				dialogue.show({
				"That's not the right object..",
				"2 minutes have been deducted!",
					}, 42, 10, 35, 18);



				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);
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
		Doorplay.PlayKnock();
		if (question == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;


			cout << "\r" << string(80, ' ') << "\r";
			cout << "What is the arrangement:";

			cin >> answerT1;

			clearQuestion(questionPos, 1);


			if (answerT1 == 2341)
			{
				dialogue.show({
				"You arrange the memories in order.",
				"\"I don't remember writing one of the lines.\"",
				"Something feels wrong,",
				"you recognize the handwriting.",
				"Then who wrote it?",
				"A faint memory surfaces, someone beside you.",
				"\"You promised you wouldn't forget.\"",
				"The door unlocks.",
					}, 48, 11, 30, 18);

				changeUnlockedState(true);
				Doorplay.PlayDoor();
				system("cls");
				question = 2;

				return;
			}
			else {
				Doorplay.PlayError();
				dialogue.show({
				"Wrong arrangement.",
				"2 minutes have been deducted!",
					}, 42, 10, 35, 18);


				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);
				return;
			}

			if (question == 2)
			{
			}

			return;


		}
	}
	if (roomID == 5) {
		Doorplay.PlayKnock();
		if (question == 1) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;

			cout << "\r" << string(80, ' ') << "\r";
			cout << "Which is the correct locker:";
			cin.clear();
			cin.sync();
			cin >> answerT1;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				answerT1 = -1; 
			}

			clearQuestion(questionPos, 1);

			if (answerT1 == 3) {
				dialogue.show({
				"You open Locker 3. The scarf is still there.",
				"A memory surfaces, you sitting across from them.",
				"The seat beside you was empty.",
				"\"You were here...\"",
				"\"Then why do I remember being alone?\"",
					}, 50, 10, 28, 18);


				changeUnlockedState(true);
				Doorplay.PlayDoor();
				system("cls");
				question = 2;
				return;
			}
			else {
				Doorplay.PlayError();
				dialogue.show({
				"Wrong answer.",
				"2 minutes have been deducted!",
					}, 42, 10, 35, 18);


				system("cls");
				getGameMap().timer.decreaseTime(2 * 60);
				return;
				

			}
		}

		if (question == 2) {
			return;
		}

		return;

	}
	if (roomID == 6) {
		char confirm;
		Doorplay.PlayKnock();
		if (doorID == 1)
		{
			Doorplay.PlayError();
			cout << "Unlock the suitcase first";
		}
		if (doorID >= 61 && doorID <= 63)
		{

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hConsole, &info);

			COORD questionPos = info.dwCursorPosition;

			cout << "Are you sure you want to enter Door "
				<< doorID - 60 << "? (Y/N): ";


			cin >> confirm;
			clearQuestion(questionPos, 1);
			
			if (confirm == 'N' || confirm == 'n')
			{
				dialogue.show({
				"You decide not to enter the door."
					}, 42, 10, 35, 18);
				system("cls");
				return;
			}

			if (confirm == 'Y' || confirm == 'y')
			{

				if (doorID == 61)
				{

					Doorplay.StopAll();
					// BAD ENDING
					Doorplay.PlayDoor();
					Doorplay.Ending1();
					dialogue.show({
						"You step through the door, expecting freedom.",
						"Instead, you find yourself back in Carriage 1. ",
						"The furnace erupts in violet flames as the train accelerates into the darkness.",
						"You turn back, but the door is gone. ",
						"You couldn't face what happened at 11:35. ",
						"Here, you never have to remember. You never have to mourn.",
						"You never have to admit they're gone. ",
						"The loop begins again. ",
						"THE END...",

						}, 84, 11, 15, 18);
					system("cls");
				}
				else if (doorID == 62)
				{
					Doorplay.StopAll();

					// NEUTRAL ENDING
					Doorplay.Ending2();
					Doorplay.PlayDoor();
					dialogue.show({
							"You step through Door 2. ",
							"Your reflection stands waiting on the other side. ",
							"\"You know what happened.\" ",
							"You simply stare at yourself. The train begins to slow. ",
							"The purple flames shrink, but they do not disappear. ",
							"\"I accept it.\"",
							"You step forward, but the train remains behind you,",
							"still burning quietly in the darkness.",
							"You have accepted the truth, but you haven't let go.",
							"THE END...",

						}, 78, 11, 15, 18);
					system("cls");

				}
				else if (doorID == 63)
				{
					Doorplay.StopAll();
					// TRUE ENDING
					Doorplay.PlayDoor();
					Doorplay.Ending3();
					dialogue.show({
					"You ignore the false exits and walk toward the furnace.",
					"The dark purple flames roar with every suppressed tear and buried memory.",
					"You do not turn away. You reach through the flames and grasp the EMERGENCY BRAKE.",
					"You pull, and the train screeches violently before finally coming to a halt.",
					"The furnace fades to embers. Silence fills the carriage.",
					"You open the door. There is no abyss, only a quiet tunnel and daylight ahead.",
					"You take a breath and walk toward the light.",
					"For the first time, you move forward. The train will never run again.",
					"THE END..."
						}, 84, 11, 15, 18);
					system("cls");
				}
			}

			if (doorID >= 61) {
				getGameMap().setEndingReached(doorID - 61);
				getGameMap().setEnded(true);
			}

			return;

		}
	}
}

