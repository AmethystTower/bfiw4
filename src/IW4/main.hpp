#pragma once

#include <iostream>
#include <conio.h>			//needed for _getch()
#include <thread>			//needed for threads
#include <windows.h>		//used for Sleep()

#include "Utils/Structs.hpp"	//includes all needed structs, variables and functions.
#include "Utils/Waves.hpp"		//includes all the wavesthe player must survive.
#include "Utils/Stats.hpp"		//include the stats view function.

//variables used by main.cpp
char character;
bool juggernautAvailable = true;
soldier temp;
soldier Squad[4];

//functions used by main.cpp
void SetupGame();
void StartGame();
void EndCinematic();

//external functions
soldier AddSoldier(std::string soldierType);