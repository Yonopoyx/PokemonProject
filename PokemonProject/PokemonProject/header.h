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

struct pokemon
{
	string name;
	string type;
	string move;

	int health;
	int damage;
};

//(Ben)
void welcomeMessage();
void choiceMessage();
void confirmPokemon(pokemon player);
void encounterMessage(pokemon enemy);

int randomNumGen(int min, int max);


pokemon getPlayerPokemon(char playerChoice);
pokemon generateEnemyPokemon();

void randomEncounter(pokemon player);

//void attack(pokemon attacker, pokemon defender);
void attack(pokemon attacker, pokemon &defender); //pass by reference

double attackMultiplier(string attackType, string defendType);

void run();