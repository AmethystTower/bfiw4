#include "Waves.hpp"
#include <conio.h>
#include <iostream>

void Wave1()
{
	disableStatsChecking = true;
	num_enemies = 5;

	for(int i = 0; i< num_enemies; i++)
		enemies[i] = SpawnEnemy(500.0f, 1.0f, 0.1f, false, false, true, "Soldier");

	Choices();
}

void Choices()
{
	char choice;
	int Fighter;
	int active_enemy = 0;
	bool playerWon = false;
	int soldiers_left = 0;

	for (;;)
	{
		system("cls");
		soldiers_left = 0;

		std::cout << "\nWave 1:\n\n";

		for (int i = 0; i < num_enemies; i++)
		{
			std::cout << "Enemy " << i+1 << ": " << enemies[i].type << "\nHealth: " << enemies[i].health << "\nDamage: " << enemies[i].damage << "\nFire Time: " << enemies[i].firetime << "\n\n";
			
			//I'm lazy so the active enemy will always be the last one.
			active_enemy = i;
		}

			disableStatsChecking = false;
			//std::cout << "\nYour turn: What would you like to do?\n\n" << "1. Fight\nS. Check own soldier stats.\n\n";
			std::cout << "\nWhat would you like to do?\n\n" << "1. Fight\n\n";

		for (;;)
		{
			choice = _getch();
			choice = tolower(choice);

			//S is not included because we have an external thread running on it.
			switch (choice)
			{
			case '1':
				Fighter = ChooseSoldier();

				if( !Squad[Fighter].isDead )
					playerWon = Combat(Fighter, active_enemy);
				//he chose a dead soldier? do nothing.
				break;
			default:
				//do nothing, player must choose 1 to continue.
			break;
			}

			if (playerWon)
			{
				num_enemies--;
				break;
			}
		}

		std::cout << "\n---------------------------------------------------------\n";
		std::cout << "\nPress any key to continue.\n\n";
		_getch();

		if(num_enemies <= 0)
		{ 
			std::cout << "\nCongratulations! You won! Playing end cinematic in 10 seconds...\n\n";
			Sleep(1000);
			EndCinematic();
			break;
		}
		
		for (int m = 0; m < 4; m++)
		{
			if (!Squad[Fighter].isDead)
				soldiers_left++;
		}

		if( soldiers_left <= 0)
		{
			std::cout << "\nYou lost! Better luck next time... press any key to quit.\n\n";
			return;
		}
	}
}