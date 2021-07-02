#pragma once

#include <string>

//the weapon used by the soldier.
struct weapons
{
	//the damage that will determine how much bullets are needed to defeat an enemy.
	float damage = 0.0f;
	//the weapon fire cooldown.
	float firetime = 0.0f;
	//the maximum ammunition the soldier can carry. if reaches 0, he'll lose the battle.
	int maxammo = 0;
	//the weapon name and type, obviously.
	std::string weaponName = "";
};

//the grenades used by the soldier, if has any. they serve as a battle advantage and deal initial damage or prevent the opponent from doing damage.
struct grenades
{
	//the amount of grenades carried by the soldier.
	int maxammo = 0;
	//the grenade type.
	std::string grenadeType = "";
};

struct soldier
{
	//the soldier's current health.
	float health = 0.0f;
	//the soldier's maximum health.
	float maxhealth = 0.0f;
	//the soldier's current armor.
	float armor = 0.0f;
	//the soldier's maximum armor.
	float maxarmor = 0.0f;
	//the soldier's weapon info.
	weapons weapon;
	//the soldier's grenade type.
	grenades grenade;
	//the soldier type.
	std::string type = "None.";
	//obviously he's alive when added to the game.
	bool isDead = false;
	std::string status = "Alive";
};

struct enemy
{
	std::string type;

	float health = 0.0f;
	float damage = 0.0f;
	float firetime = 0.0f;

	bool isVehicle;
	bool isSoldier;
	bool isArmored;
	bool isDead = false;
};