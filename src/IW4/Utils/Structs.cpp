#include "Structs.hpp"

soldier AddSoldier(std::string soldierType)
{
	soldier Soldiers;

	//default class. average damage, sustainability and survivability. avarage against all types of soldiers.
	if( soldierType == "assault" )
	{ 
		Soldiers.health = 150.0f;
		Soldiers.maxhealth = 150.0f;

		Soldiers.armor = 0.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 30.0f;
		Soldiers.weapon.firetime = 0.08f;
		Soldiers.weapon.maxammo = 280;
		Soldiers.weapon.weaponName = "AK-47 Tactical";

		Soldiers.grenade.maxammo = 1;
		Soldiers.grenade.grenadeType = "Frag Grenade";

		Soldiers.type = "Assault";
	}
	//decent damage per second and ammunition pool but weak survivability, though comes with 3 concussion grenades. strong against normal soldiers.
	else if ( soldierType == "special_ops" )
	{
		Soldiers.health = 100.0f;
		Soldiers.maxhealth = 100.0f;

		Soldiers.armor = 0.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 17.0f;
		Soldiers.weapon.firetime = 0.058f;
		Soldiers.weapon.maxammo = 448;
		Soldiers.weapon.weaponName = "PP90M1";

		Soldiers.grenade.maxammo = 3;
		Soldiers.grenade.grenadeType = "Concussion Grenade";

		Soldiers.type = "Special Ops";
	}
	//good damage and sustainability as well as survivability, but is useless against air support. strong against all types of soldiers.
	else if (soldierType == "cqb")
	{
		Soldiers.health = 250.0f;
		Soldiers.maxhealth = 250.0f;

		Soldiers.armor = 100.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 200.0f;
		Soldiers.weapon.firetime = 0.936f;
		Soldiers.weapon.maxammo = 56;
		Soldiers.weapon.weaponName = "Spas-12";

		Soldiers.grenade.maxammo = 1;
		Soldiers.grenade.grenadeType = "Concussion Grenade";

		Soldiers.type = "CQB";
	}
	//decent damage per second and sustainability, but no grenades. strong against all types of soldiers.
	else if (soldierType == "support")
	{
		Soldiers.health = 150.0f;
		Soldiers.maxhealth = 150.0f;

		Soldiers.armor = 25.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 45.0f;
		Soldiers.weapon.firetime = 0.1f;
		Soldiers.weapon.maxammo = 500;
		Soldiers.weapon.weaponName = "RPD";

		Soldiers.grenade.maxammo = 0;
		Soldiers.grenade.grenadeType = "none";

		Soldiers.type = "Support";
	}
	//powerful but out of ammunition quickly. a must-have for battles against vehicles. strong against all types of enemies.
	else if (soldierType == "demolitions")
	{
		Soldiers.health = 300.0f;
		Soldiers.maxhealth = 300.0f;

		Soldiers.armor = 50.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 1500.0f;
		Soldiers.weapon.firetime = 1.059f;
		Soldiers.weapon.maxammo = 4;
		Soldiers.weapon.weaponName = "AT4";

		Soldiers.grenade.maxammo = 1;
		Soldiers.grenade.grenadeType = "Anti-Tank Grenade";

		Soldiers.type = "Demolitions Expert";
	}
	//high risk, high reward with very good ammunition efficiency. strong against normal soldiers, weak against all other types of enemies.
	else if (soldierType == "scout")
	{
		Soldiers.health = 50.0f;
		Soldiers.maxhealth = 50.0f;

		Soldiers.armor = 0.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 500.0f;
		Soldiers.weapon.firetime = 1.115f;
		Soldiers.weapon.maxammo = 35;
		Soldiers.weapon.weaponName = "CheyTac M200";

		Soldiers.grenade.maxammo = 3;
		Soldiers.grenade.grenadeType = "Throwing Knife";

		Soldiers.type = "Scout Sniper";
	}
	//has higher damage per second, but overall deals less damage than the sniper. strong against all types of soldiers, weak against vehicles due to high ammunition consumption.
	else if (soldierType == "marksman")
	{
		Soldiers.health = 150.0f;
		Soldiers.maxhealth = 150.0f;

		Soldiers.armor = 0.0f;
		Soldiers.maxarmor = 100.0f;

		Soldiers.weapon.damage = 150.0f;
		Soldiers.weapon.firetime = 0.12f;
		Soldiers.weapon.maxammo = 70;
		Soldiers.weapon.weaponName = "Dragunov";

		Soldiers.grenade.maxammo = 1;
		Soldiers.grenade.grenadeType = "Throwing Knife";

		Soldiers.type = "Marksman";
	}
	//the juggernaut is limited to 1 per game. very strong against all types of enemies.
	else if (soldierType == "juggernaut")
	{
		Soldiers.health = 300.0f;
		Soldiers.maxhealth = 300.0f;

		Soldiers.armor = 1000.0f;
		Soldiers.maxarmor = 1000.0f;

		Soldiers.weapon.damage = 49.0f;
		Soldiers.weapon.firetime = 0.045f;
		Soldiers.weapon.maxammo = 800;
		Soldiers.weapon.weaponName = "Terminator Minigun";

		Soldiers.grenade.maxammo = 0;
		Soldiers.grenade.grenadeType = "none";

		Soldiers.type = "Juggernaut";
	}

	return Soldiers;
}

enemy SpawnEnemy(float health, float damage, float firetime, bool isVehicle, bool isSoldier, bool isArmored, std::string enemyType)
{
	enemy enemies;

	enemies.health = health;
	enemies.damage = damage;
	enemies.firetime = firetime;
	enemies.isVehicle = isVehicle;
	enemies.isSoldier = isSoldier;
	enemies.isArmored = isArmored;

	if (enemyType == "soldier")
		enemies.type = "Soldier";
	else if (enemyType == "armored")
		enemies.type = "Armored Soldier";
	else if (enemyType == "harrier")
		enemies.type == "Harrier";
	else if (enemyType == "helicopter")
		enemies.type == "Attack Helicopter";
	else if (enemyType == "littlebird")
		enemies.type == "Little Bird";
	else if (enemyType == "juggernaut")
		enemies.type == "Juggernaut";

	return enemies;
}