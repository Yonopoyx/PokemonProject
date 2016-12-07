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

#include <random>
#include <time.h>
#include<iostream>
#include"header.h"

using namespace std;

int battlesFought = 0;
int victories = 0;
int damageDealt = 0;//Player lifetime stats

//Starting text (Ben)
void welcomeMessage()
{
	cout << "Welcome to Pokemon Ink, a text-based Pokemon battle simulator!" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "I am Professor Evergreen from Visual Studios, the company behind this simulation." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "This simulation world is filled with many kinds of Pokemon for you to meet and battle with." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "What are Pokemon? For some, Pokemon are pets. For others, and the purpose of this" << endl;
	cout << "simulation, Pokemon are for battling other Pokemon to protect their trainer." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Since this is only a simulation, Pokemon cannot be caught." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "In this simulation, you will be given several choices of Pokemon to choose from." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "After you select your Pokemon, this world will play out elimination-style:" << endl;
	cout << "Keep battling until all of your Pokemon have been KO-ed!" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "How does battling work? Allow me to explain." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "When an enemy Pokemon appears, you will have the option to attack or run away." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "If you attack, the enemy Pokemon will take damage, then attack your Pokemon" << endl;
	cout << "in a turn-based sequence until the health points (or HP for short) of one" << endl;
	cout << "Pokemon reaches 0, signifying a KO." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "When the enemy Pokemon is KO-ed, it means you win the battle!" << endl;
	cout << "But if your Pokemon gets KO-ed, you lose the battle and your simulation is over." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Running away allows you to leave the battle and continue your simulation, but" << endl;
	cout << "this may not work, and you will be forced to attack for the rest of the battle." << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Now that you know the rules, get out there and win as many battles as you can, and have fun!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "First things first however, you'll need a Pokemon." << endl;
	cout << endl;
	system("pause");
	system("cls");
}

//Text for choosing pokemon (Ben)
void choiceMessage()
{
	cout << "You can pick from the following Pokemon:" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << "Squirtle, the water Pokemon!" << endl;
	cout << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << "Squirtle, the water Pokemon!" << endl;
	cout << endl;
	cout << "If you chose Bulbasaur, enter 'b'. If you chose Charmander," << endl;
	cout << "enter 'c'. If you chose Squirtle, enter 's'." << endl;
	cout << endl;
	cout << "Please select a Pokemon:" << endl;
	cout << endl;

}

//Confirm player's pokemon choice (Ben)
void confirmPokemon(pokemon player)
{
	cout << "You chose..." << endl;
	cout << player.name << endl;
	cout << player.type << " Type" << endl;
	cout << "HP: " << player.health << endl;
	cout << "Damage: " << player.damage << endl << endl;

	cout << "Are you sure this is the pokemon for you?" << endl;
	cout << "Enter 'y' yes or 'n' for no" << endl;
}

//Displays text for random encounters (Ben)
void encounterMessage(pokemon enemyPokemon)
{
	cout << "A wild " << enemyPokemon.name << " appeared!" << endl << endl;
	cout << "Battle with 'b' " << endl;
	cout << "Attempt to run with 'r' " << endl;

}

//Returns a random int (Ben)
int randomNumGen(int min, int max)
{
	srand(time(0));

	int num = rand() % (max - min + 1) + min;

	return num;
}

//The random encounter battle loop - allows player to run or fight (Ben/Walter)
bool randomEncounter(pokemon player)
{
	bool fainted = false; //checks pokemon health
	
	int numBattles = 0; //increments battle loop
	int maxBattles = 5; //exits battle loop

	while (numBattles < 5)
	{
		pokemon enemy = generateEnemyPokemon();
		char battleAction;
		bool playerTurn = true;

		cout << "[Battle no. " << (1 + numBattles) << " of " << maxBattles << "]" << endl;
		encounterMessage(enemy);
		cin >> battleAction;

		//For player input error during battle
		while (battleAction != 'b' && battleAction != 'r')
		{
			cout << "Please enter a valid move command" << endl << endl;
			cout << "Battle with 'b' " << endl;
			cout << "Attempt to run with 'r' " << endl;

			cin >> battleAction;
		}

		//turn based battle loop
		while (player.health > 0 && enemy.health > 0)
		{
			if (playerTurn)
			{
				if (battleAction == 'b')
				{
					
					cout << endl;
					cout << player.name << " used " << player.move << "!" << endl;
					attack(player, enemy);
					cout << endl;

					fainted = hasFainted(enemy);
					if (fainted == true)
					{
						numBattles++;
						
						battlesFought++;
						victories++;

						cout << endl << "The wild " << enemy.name << " has fainted." << endl << endl;
						cout << "Your " << player.name << "'s HP: " << player.health << endl;
						cout << endl << "Continue thru the tall grass." << endl;
						system("pause");
						system("cls");
					}
					else
					{
						playerTurn = false;
						system("pause");
					}
				}
				else if (battleAction == 'r')
				{
					

					int runChance = randomNumGen(0, 49);
					if (runChance >= 0 && runChance <= 34)
					{
						battlesFought++;

						cout << endl;
						cout << "You escaped!" << endl;
						cout << "" << endl;
						system("pause");
						system("cls");
						enemy = generateEnemyPokemon();
						cout << "[Battle no. " << (1 + numBattles) << " of " << maxBattles << "]" << endl;
						encounterMessage(enemy);
						cin >> battleAction;
					}
					else
					{
						cout << endl;
						cout << "Can't escape! Now you must battle"<< endl << endl;
						battleAction = 'b';
						playerTurn = false;
					}
				}
			}
			else
			{
				cout << endl;
				cout << "The wild " << enemy.name << " used " << enemy.move << "!" << endl;
				attack(enemy, player);

				if (player.health <= 0)
				{
					cout << "Your " << player.name << "'s HP: 0" << endl;
					cout << endl;
				}
				else
				{
					cout << "Your " << player.name << "'s HP: " << player.health << endl;
					cout << endl;
				}

				fainted = hasFainted(player);
				if (fainted == true)
				{
					numBattles = maxBattles;
					cout << "Your pokemon has fainted." << endl;
					system("pause");
					system("cls");
				}
				else
				{
					playerTurn = true;
					system("pause");
				}
			}
		}
	}
	return postgame();
}

//Displays lifetime stats
//Allows user to exit/restart (Walter)
bool postgame()
{
	char gameControl; 

	cout << "You did well. But with more training you could go even further!" << endl;
	
	system("pause");
	system("cls");

	cout << "STATS" << endl;
	cout << "==============================================================" << endl << endl;
	cout << "Pokemon encountered | "<< battlesFought << endl;
	cout << "Victories | " << victories << endl << endl;

	cout << "Damage Dealt | " << damageDealt << endl << endl;
	


	cout << "Do you want to continue your journey or return home?" << endl;
	cout << "Press 'c' to continue or 'q' to quit the game." << endl;
	cin >> gameControl;
	
	if (gameControl == 'c')
	{
		system("cls");
		return true;
	}
	else if (gameControl == 'q')
	{
		system("cls");
		return false;
	}
	while (gameControl != 'c' && gameControl!= 'q' )
	{
		cout << "Please enter a valid command" << endl;
		cout << "Press 'c' to continue or 'q' to quit the game." << endl;

		cin >> gameControl;
	}

	return false;

}

//The player can pick from 1 of 3 starters(Walter)
pokemon getPlayerPokemon(char playerChoice)
{
	if (playerChoice == 'b')
	{
		pokemon bulbasaur;

		bulbasaur.name = "Bulbasaur";
		bulbasaur.type = "Grass";
		bulbasaur.health = 70;
		bulbasaur.damage = 16;
		bulbasaur.move = "Razor Leaf";


		return bulbasaur;
	}

	else if (playerChoice == 'c')
	{
		pokemon charmander;

		charmander.name = "Charmander";
		charmander.type = "Fire";
		charmander.health = 70;
		charmander.damage = 16;
		charmander.move = "Ember";

		return charmander;
	}

	else if (playerChoice == 's')
	{
		pokemon squirtle;

		squirtle.name = "Squirtle";
		squirtle.type = "Water";
		squirtle.health = 70;
		squirtle.damage = 16;
		squirtle.move = "Bubblebeam";


		return squirtle;
	}
	else
	{
		cout << "ERROR --->	2 \n" << endl;
		exit(2);
	}
}

//randomly genereates a wild pokemon (Ben/Walter)
pokemon generateEnemyPokemon()
{
	int randNum;
	randNum = randomNumGen(0, 50);

	//Bulbasaur
	if (randNum == 0 || randNum == 1)
	{
		pokemon bulbasaur;

		bulbasaur.name = "Bulbasaur";
		bulbasaur.type = "Grass";
		bulbasaur.health = 35;
		bulbasaur.damage = 12;
		bulbasaur.move = "Razor Leaf";

		return bulbasaur;
	}

	//Charmander
	else if (randNum == 2 || randNum == 3)
	{
		pokemon charmander;

		charmander.name = "Charmander";
		charmander.type = "Fire";
		charmander.health = 35;
		charmander.damage = 12;
		charmander.move = "Ember";

		return charmander;
	}

	//Squirtle
	else if (randNum == 4 || randNum == 5)
	{
		pokemon squirtle;

		squirtle.name = "Squirtle";
		squirtle.type = "Water";
		squirtle.health = 35;
		squirtle.damage = 12;
		squirtle.move = "Bubblebeam";

		return squirtle;
	}

	//Rattata
	else if (randNum >= 6 && randNum <= 11)
	{
		pokemon rattata;

		rattata.name = "Rattata";
		rattata.type = "Normal";
		rattata.health = 28;
		rattata.damage = 10;
		rattata.move = "Hyper Fang";

		return rattata;
	}

	//Machop	
	else if (randNum >= 12 && randNum <= 14)
	{
		pokemon machop;

		machop.name = "Machop";
		machop.type = "Fighting";
		machop.health = 32;
		machop.damage = 12;
		machop.move = "Low Kick";

		return machop;
	}

	//Pikachu
	else if (randNum == 15 || randNum == 16)
	{
		pokemon pikachu;

		pikachu.name = "Pikachu";
		pikachu.type = "Electric";
		pikachu.health = 35;
		pikachu.damage = 14;
		pikachu.move = "Thundershock";

		return pikachu;
	}

	//Ekans
	else if (randNum >= 17 && randNum <= 19)
	{
		pokemon ekans;

		ekans.name = "Ekans";
		ekans.type = "Poison";
		ekans.health = 30;
		ekans.damage = 16;
		ekans.move = "Poison Tail";

		return ekans;
	}

	//Onix
	else if (randNum >= 20 && randNum <= 22)
	{
		pokemon onix;

		onix.name = "Onix";
		onix.type = "Rock";
		onix.health = 45;
		onix.damage = 8;
		onix.move = "Rock Throw";

		return onix;
	}

	//Cubone
	else if (randNum >= 23 && randNum <= 25)
	{
		pokemon cubone;

		cubone.name = "Cubone";
		cubone.type = "Ground";
		cubone.health = 34;
		cubone.damage = 12;
		cubone.move = "Bone Club";
		return cubone;
	}

	//Dratini
	else if (randNum == 26)
	{
		pokemon dratini;

		dratini.name = "Dratini";
		dratini.type = "Dragon";
		dratini.health = 40;
		dratini.damage = 16;
		dratini.move = "Dragonbreath";

		return dratini;
	}

	//Spearow
	else if (randNum >= 27 && randNum <= 32)
	{
		pokemon spearow;

		spearow.name = "Spearow";
		spearow.type = "Flying";
		spearow.health = 30;
		spearow.damage = 12;
		spearow.move = "Wing Attack";

		return spearow;
	}

	//Gastly
	else if (randNum == 33 || randNum == 34)
	{
		pokemon gastly;

		gastly.name = "Gastly";
		gastly.type = "Ghost";
		gastly.health = 32;
		gastly.damage = 14;
		gastly.move = "Shadow Sneak";

		return gastly;
	}

	//Abra
	else if (randNum >= 35 && randNum <= 37)
	{
		pokemon abra;

		abra.name = "Abra";
		abra.type = "Psychic";
		abra.health = 32;
		abra.damage = 8;
		abra.move = "Psybeam";

		return abra;
	}

	//Caterpie
	else if (randNum >= 38 && randNum <= 43)
	{
		pokemon caterpie;

		caterpie.name = "Caterpie";
		caterpie.type = "Bug";
		caterpie.health = 28;
		caterpie.damage = 10;
		caterpie.move = "Bug Bite";

		return caterpie;
	}

	//Mew
	else if (randNum == 44)
	{
		pokemon mew;

		mew.name = "Mew";
		mew.type = "Psychic";
		mew.health = 50;
		mew.damage = 18;
		mew.move = "Psyshock";

		return mew;
	}

	//Snorunt
	else if (randNum >= 45 && randNum <= 47)
	{
		pokemon snorunt;

		snorunt.name = "Snorunt";
		snorunt.type = "Ice";
		snorunt.health = 35;
		snorunt.damage = 12;
		snorunt.move = "Aurora Beam";

		return snorunt;
	}

	//Magikarp
	else if (randNum == 48 || randNum == 49)
	{
		pokemon magikarp;

		magikarp.name = "Magikarp";
		magikarp.type = "magikarpType";
		magikarp.health = 20;
		magikarp.damage = 0;

		int magikarpChance = randomNumGen(0, 49);
		if (magikarpChance >= 0 && magikarpChance <= 48)
		{
			magikarp.move = "Splash";
		}
		else
		{
			magikarp.move = "Hyperbeam! Just kidding. Magikarp used Splash";
		}

		return magikarp;
	}
	else
	{
		cout << "ERROR - 1 \n" << endl;
		exit(1);
	}
}


//Applies attacker damage + multiplier to defending pokemon's health (Walter)
void attack(pokemon attacker, pokemon &defender)
{
	bool isPlayerAttack = true;

	string attackerType = attacker.type;
	string defenderType = defender.type;

	double multiplier = attackMultiplier(attackerType, defenderType);
	double attackDamage = attacker.damage * multiplier;	 
	
	if (isPlayerAttack)//tracks player damage dealt
	{
		damageDealt += attackDamage;
		isPlayerAttack = false;
	}
	defender.health =  defender.health - attackDamage;
}

//Checks pokemon types to determine effectiveness & ATK multiplier (Ben/Walter)
double attackMultiplier(string attackType, string defendType)
{
	double dmgMultiplier;
	if (attackType == "Fire")
	{
		//Not very effective
		if (defendType == "Fire" || defendType == "Water"|| defendType == "Dragon"|| 
			defendType == "Rock"|| defendType == "Ground")
		{
			dmgMultiplier = 0.5;
			return dmgMultiplier;
		}
		//Very effective
		else if (defendType == "Ice" || defendType == "Bug" || defendType == "Grass")
		{
			dmgMultiplier = 2;
			return dmgMultiplier;
		}
	}

	else if (attackType == "Water")
	{
		//Not very effective
		if (defendType == "Grass" || defendType == "Water" || defendType == "Dragon")
		{
			dmgMultiplier = 0.5;
			return dmgMultiplier;
		}
		//Very effective
		else if (defendType == "Rock" || defendType == "Ground" || defendType == "Fire")
		{
			dmgMultiplier = 2;
			return dmgMultiplier;
		}
	}

	else if (attackType == "Grass")
	{
		//Not very effective
		if (defendType == "Fire" || defendType == "Grass" || defendType == "Dragon" ||
			defendType == "Bug" || defendType == "Poison" || defendType == "Flying")
		{
			dmgMultiplier = 0.5;
			return dmgMultiplier;
		}
		//Very effective
		else if (defendType == "Water" || defendType == "Rock" || defendType == "Ground")
		{
			dmgMultiplier = 2;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Ground")
	{
		if (defendType == "Fire")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
		else if (defendType == "Grass" || defendType == "Water")
		{
			dmgMultiplier = 0.5;
			cout << "It's not very effective..." << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Poison")
	{
		if (defendType == "Grass")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Electric")
	{
		if (defendType == "Water")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
		else if (defendType == "Grass")
		{
			dmgMultiplier = 0.5;
			cout << "It's not very effective..." << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Rock")
	{
		if (defendType == "Fire")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
		else if (defendType == "Grass")
		{
			dmgMultiplier = 0.5;
			cout << "It's not very effective..." << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Bug")
	{
		if (defendType == "Grass")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
		else if (defendType == "Fire")
		{
			dmgMultiplier = 0.5;
			cout << "It's not very effective..." << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Flying")
	{
		if (defendType == "Grass")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "Ice")
	{
		if (defendType == "Grass")
		{
			dmgMultiplier = 2;
			cout << "It's super effective!" << endl;
			return dmgMultiplier;
		}
		else if (defendType == "Fire" || defendType == "Water")
		{
			dmgMultiplier = 0.5;
			cout << "It's not very effective..." << endl;
			return dmgMultiplier;
		}
	}
	else if (attackType == "magikarpType")
	{
		cout << "BUT NOTHING HAPPENED." << endl;
	}

	//Standard damage
	return 1;
}

//Checks if pokemon has zero health left (Walter)
bool hasFainted(pokemon &defender)
{
	if (defender.health <= 0)
	{
		//pokemon faints - fuction or in here??
		return true;
	}
	return false;
}