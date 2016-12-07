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

#pragma once
#include <string>

using namespace std;

//Player stats that carry over thru the rounds of 5 
//or a player's pokemon fainting
extern int battlesFought;
extern int victories;
extern int damageDealt;

//Player and enemy pokemon follow this struct
struct pokemon
{
	string name;
	string type;
	string move;

	int health;
	int damage;
};

//Starting text (Ben)
void welcomeMessage();

//Text for choosing pokemon (Ben)
void choiceMessage();

//Confirm player's pokemon choice (Ben)
void confirmPokemon(pokemon player);

//Displays text for random encounters (Ben)
void encounterMessage(pokemon enemy);

//Returns a random int (Ben)
int randomNumGen(int min, int max);

//The player can pick from 1 of 3 starters(Walter)
pokemon getPlayerPokemon(char playerChoice);

//randomly genereates a wild pokemon (Walter)
pokemon generateEnemyPokemon();

//The random encounter battle loop - allows player to run or fight
//Tracks wins and encounters (Ben/Walter)
bool randomEncounter(pokemon player);

//Checks pokemon types to determine effectiveness & ATK multiplier (Walter)
void attack(pokemon attacker, pokemon &defender);

//Checks if pokemon has zero health left (Walter)
bool hasFainted(pokemon &defender);

//Checks pokemon types to determine effectiveness & ATK multiplier (Ben/Walter)
double attackMultiplier(string attackType, string defendType);

//Displays lifetime stats
//Allows user to exit/restart (Walter)
bool postgame();	