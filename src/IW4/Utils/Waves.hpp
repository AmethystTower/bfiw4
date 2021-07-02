#pragma once

#include "Structs.hpp"
#include "Combat.hpp"

bool disableStatsChecking;
int num_enemies;

enemy enemies[5];		//max 5 enemies at a time.

void Choices();
void Wave1();

//external functions
enemy SpawnEnemy(float health, float damage, float firetime, bool isVehicle, bool isSoldier, bool isArmored, std::string enemyType);