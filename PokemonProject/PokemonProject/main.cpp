/*
Author: Ben Donahue & Walter Hill
Class: Intro to Programming(CSI 140-08)
Assignment: Final Project
Date Assigned: 11/29/16
Due Date: 12/9/16

Program Description: Final Project - TBD

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>	
#include "header.h"
#include <string>

using namespace std;

int main()
{
	//Console formatting
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);

	char playerChoice; //to choose player's starter
	char playerConfirm; //to confirm choices
	pokemon playerPokemon; //Player's starter pokemon

	bool inBattle; //For initializing battle loop
	bool isLive = true; //Holds game state
	int numBattles = 0; //Tracks number of encounters in a wave
	
	//Start menu & story explanation
	welcomeMessage();

	while (isLive)
	{
		//Player chooses starter
		choiceMessage();
		cin >> playerChoice;

		//For player input error when choosing starter
		while (playerChoice != 'b' && playerChoice != 'c' && playerChoice != 's')
		{
			choiceMessage();
			cin >> playerChoice;
		}
		system("cls");

		//Gets player pokemon stats
		playerPokemon = getPlayerPokemon(playerChoice);
		confirmPokemon(playerPokemon);
		cin >> playerConfirm;

		//begin battle loop if ready
		if (playerConfirm == 'y')
		{
			inBattle = true;

			cout << endl << "Entering the tall grass..." << endl << endl;

			system("pause");
			system("cls");
		}

		while (playerConfirm == 'n')
		{
			choiceMessage();
			cin >> playerChoice;

			playerPokemon = getPlayerPokemon(playerChoice);
			confirmPokemon(playerPokemon);
			cin >> playerConfirm;

			if (playerConfirm == 'y')
			{
				inBattle = true;

				cout << endl << "Entering the tall grass..." << endl << endl;

				system("pause");
				system("cls");
			}
		}
		
		//controls battle loop & alters game state
		isLive = randomEncounter(playerPokemon);
	}
	return 0;
}