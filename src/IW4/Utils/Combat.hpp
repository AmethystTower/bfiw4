#pragma once

#include "main.hpp"		//nothing new will be added here except for combat-related functions. for this we need to include everything.

//player chooses a soldier based off an integer, the integer will then determine which soldiers are picked from the array.
int ChooseSoldier();

//the combat functions.
bool Combat(int PlayerSoldier, int Combatant);
float DealtDamagePlayer(int PlayerSoldier);
float DealtDamageEnemy(int Combatant);

//this is a function that applies damage modifiers to weapons and classes.
float DamageModifiers(float damage, std::string weapon, bool isPlayer, soldier PlayerSoldier, enemy Combatant);