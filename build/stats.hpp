#pragma once

#include <thread>	//needed for threads

namespace stats 
{
	bool duringCombat = false;

	std::thread CheckSoldierStats(char button1, char button2, char button3, char button4);
}