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


#include<iostream>
using namespace std;

void welcomeMessage();

void welcomeMessage()
{
   cout << "Welcome to Pokemon Ink, a text-based pokemon battle simulator!" << endl; 
}
=======
>>>>>>> origin/master

using namespace std;

//(Ben)
void welcomeMessage()
{
	cout << "Welcome to Pokemon Ink, a text-based Pokemon battle simulator!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "I am Professor Evergreen from Visual Studios, the company behind this simulation." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "This simulation world is filled with many kinds of Pokemon for you to meet and battle with." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "What are Pokemon? For some, Pokemon are pets. For others, and the purpose of this" << endl;
	cout << "simulation, Pokemon are for battling other Pokemon to protect their trainer." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Since this is only a simulation, Pokemon cannot be caught." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "In this simulation, you will be given several choices of Pokemon to choose from." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "After you select your Pokemon, this world will play out elimination-style:" << endl;
	cout << "Keep battling until all of your Pokemon have been KO-ed!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "How does battling work? Allow me to explain." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "When an enemy Pokemon appears, you will have the option to attack or run away." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "If you attack, the enemy Pokemon will take damage, then attack your Pokemon" << endl;
	cout << "in a turn-based sequence until the health points (or HP for short) of one" << endl;
	cout << "Pokemon reaches 0, signifying a KO." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "When the enemy Pokemon is KO-ed, it means you win the battle!" << endl;
	cout << "But if your Pokemon gets KO-ed, you lose the battle and your simulation is over." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Running away allows you to leave the battle and continue your simulation, but" << endl;
	cout << "this may not work, and you will be forced to attack for the rest of the battle." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Now that you know the rules, get out there and win as many battles as you can, and have fun!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "First things first however, you'll need a Pokemon." << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
}
void choiceMessage()
{
	cout << "You can pick from the following choices:" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << "Squirtle, the water Pokemon!" << endl;
	cout << "" << endl;
	system("pause");
	system("cls");
	cout << "Bulbasaur, the grass Pokemon!" << endl;
	cout << "Charmander, the fire Pokemon!" << endl;
	cout << "Squirtle, the water Pokemon!" << endl;
	cout << "" << endl;
	cout << "If you chose Bulbasaur, enter 'b'. If you chose Charmander," << endl;
	cout << "enter 'c'. If you chose Squirtle, enter 's'." << endl;
	cout << "" << endl;
	cout << "Please select a Pokemon:" << endl;
	cout << "" << endl;

}
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
void encounterMessage(pokemon enemyPokemon)
{
	cout << "A wild " << enemyPokemon.name << " appeared!" << endl << endl;
	cout << "Attack with 'a' " << endl;
	cout << "Attempt to run with 'r' " << endl;

}

//Returns a random int (Ben)
int randomNumGen(int min, int max)
{
	srand(time(0));

	int num = rand() % (max - min + 1) + min;

	return num;
}

//The player can pick from 1 of 3 starters(Walter)
pokemon getPlayerPokemon(char playerChoice)
{
	if (playerChoice == 'b')
	{
		pokemon bulbasaur;

		bulbasaur.name = "Bulbasaur";
		bulbasaur.type = "Grass";
		bulbasaur.health = 35;
		bulbasaur.damage = 15;
		bulbasaur.move = "Razor Leaf";


		return bulbasaur;
	}

	else if (playerChoice == 'c')
	{
		pokemon charmander;

		charmander.name = "Charmander";
		charmander.type = "Fire";
		charmander.health = 35;
		charmander.damage = 15;
		charmander.move = "Ember";

		return charmander;
	}

	else if (playerChoice == 's')
	{
		pokemon squirtle;

		squirtle.name = "Squirtle";
		squirtle.type = "Water";
		squirtle.health = 35;
		squirtle.damage = 15;
		squirtle.move = "Bubblebeam";


		return squirtle;
	}
	else
	{
		cout << "ERROR --->	2 \n" << endl;
		exit(2);
	}
}

// (Walter)
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
		rattata.health = 32;
		rattata.damage = 16;
		rattata.move = "Hyper Fang";

		return rattata;
	}

	//Machop	
	else if (randNum >= 12 && randNum <= 14)
	{
		pokemon machop;

		machop.name = "Machop";
		machop.type = "Fighting";
		machop.health = 30;
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
		onix.damage = 10;
		onix.move = "Rock Throw";

		return onix;
	}

	//Cubone
	else if (randNum >= 23 && randNum <= 25)
	{
		pokemon cubone;

		cubone.name = "Cubone";
		cubone.type = "Ground";
		cubone.health = 35;
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
		spearow.health = 35;
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
		abra.damage = 12;
		abra.move = "Psybeam";

		return abra;
	}

	//Caterpie
	else if (randNum >= 38 && randNum <= 43)
	{
		pokemon caterpie;

		caterpie.name = "Caterpie";
		caterpie.type = "Bug";
		caterpie.health = 40;
		caterpie.damage = 14;
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
	else if (randNum >= 45 || randNum <= 47)
	{
		pokemon snorunt;

		snorunt.name = "Snorunt";
		snorunt.type = "Ice";
		snorunt.health = 35;
		snorunt.damage = 10;
		snorunt.move = "Aurora Beam";

			return snorunt;
	}

	//Magikarp
	else if (randNum == 48 || randNum == 49)
	{
		pokemon magikarp;

		magikarp.name = "Magikarp";
		magikarp.type = "Water";
		magikarp.health = 20;
		magikarp.damage = 0;
		magikarp.move = "splash";

		return magikarp;
	}
	else
	{
		cout << "ERROR - 1 \n" << endl;
		exit(1);
	}
}
void randomEncounter(pokemon player)
{
	bool inBattle = true;
	int numBattles = 0;

	while (numBattles < 5)
	{
		pokemon enemy = generateEnemyPokemon();
		char battleAction;
		bool playerTurn = true;

		encounterMessage(enemy);
		cin >> battleAction;

		//For player input error during battle
		while (battleAction != 'a' && battleAction != 'r')
		{
			cout << "Please enter a valid move command" << endl << endl;
			cout << "Attack with 'a' " << endl;
			cout << "Attempt to run with 'r' " << endl;

			cin >> battleAction;
		}

		//turn based battle loop
		while (player.health > 0 && enemy.health > 0)
		{
			if (playerTurn)
			{
				if (battleAction == 'a')
				{
					attack(player, enemy);
					//cout << player.name << " used" << /*playerPokemon.move <<*/ endl;
					//cout << enemy.name << " Enemy HP: " << enemy.health << endl;
					playerTurn = false;

					system("pause");
				}
				else if (battleAction == 'r')
				{
					//run()
					//inBattle = false;

				}
			}
			else
			{
				attack(enemy, player);
				//cout << enemy.name << " used" << /*playerPokemon.move <<*/ endl;
				//cout << enemy.name << " HP: " << enemy.health << endl;
				playerTurn = true;

				system("pause");
			}
		}
		numBattles++;

		//should running count towards num battles per wave
		//on death/enemy defeat, increment num battles

	}
	//healed every 5
}

void attack(pokemon attacker, pokemon &defender)//pass by reference - can just re-cout stats and hp should be lower
{
	string attackerType = attacker.type;
	string defenderType = defender.type;

	double multiplier = attackMultiplier(attackerType, defenderType);
	double attackDamage = attacker.damage * multiplier;	 
										 
	defender.health -= attackDamage;
	//return defender.health;
}

bool hasFainted(pokemon &defender)
{
	if (defender.health <= 0)
	{
		cout << defender.name << " fainted!" << endl;
		//pokemon faints - fuction or in here??
		return true;
	}
	return false;	
}

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
		//Standard damage
		else
		{
			dmgMultiplier = 1;
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

		//Standard damage
		else
		{
			dmgMultiplier = 1;
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
		//Standard damage
		else
		{
			dmgMultiplier = 1;
			return dmgMultiplier;
		}
	}

	return -1;
}

void run()
{

}
>>>>>>> refs/remotes/origin/master
