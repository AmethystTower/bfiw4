#include "Stats.hpp"

void Stats::MonitorButtonStats(soldier Squad[4])
{
	char key;
	int num;
	disableStatsChecking = false;

	for(;;)
	{
		key = _getch();
		key = tolower(key);

		if (disableStatsChecking || key != 's')
			continue;

		std::cout << "\nWhich soldier's stats would you like to view? Input their number.";
		std::cout << "\n\nSoldier 1: " << Squad[0].type << "\nStatus: " << Squad[0].status << "\n\nSoldier 2: " << Squad[1].type << "\nStatus: " << Squad[1].status << "\n\nSoldier 3: " << Squad[2].type << "\nStatus: " << Squad[2].status << "\n\nSoldier 4: " << Squad[3].type << "\nStatus: " << Squad[3].status << "\n";

		key = _getch();
		key = tolower(key);

		if (disableStatsChecking)		//this is a fallback incase we've already started.
			continue;

		switch (key)
		{
		case '1':	//convert char to int then print soldier stats.
			num = 0;
			if(!Squad[num].isDead)
				std::cout << "Soldier " << num + 1 << ": " << Squad[num].type << "\nWeapon: " << Squad[num].weapon.weaponName << "\nDamage: " << Squad[num].weapon.damage << "\nFire Time: " << Squad[num].weapon.firetime << "\nMax Ammo: " << Squad[num].weapon.maxammo << "\nGrenade Amount: " << Squad[num].grenade.maxammo << "\nGrenade Type: " << Squad[num].grenade.grenadeType << "\nMax. Health: " << Squad[num].maxhealth << "\nMax. Armor: " << Squad[num].maxarmor << "\nStarting Armor: " << Squad[num].armor << "\n\n\n";
			else
				std::cout << "\n\nThis soldier is dead.";
		break;
		case '2':
			num = 1;
			if (!Squad[num].isDead)
				std::cout << "Soldier " << num + 1 << ": " << Squad[num].type << "\nWeapon: " << Squad[num].weapon.weaponName << "\nDamage: " << Squad[num].weapon.damage << "\nFire Time: " << Squad[num].weapon.firetime << "\nMax Ammo: " << Squad[num].weapon.maxammo << "\nGrenade Amount: " << Squad[num].grenade.maxammo << "\nGrenade Type: " << Squad[num].grenade.grenadeType << "\nMax. Health: " << Squad[num].maxhealth << "\nMax. Armor: " << Squad[num].maxarmor << "\nStarting Armor: " << Squad[num].armor << "\n\n\n";
			else
				std::cout << "\n\nThis soldier is dead.";
		break;
		case '3':
			num = 2;
			if (!Squad[num].isDead)
				std::cout << "Soldier " << num + 1 << ": " << Squad[num].type << "\nWeapon: " << Squad[num].weapon.weaponName << "\nDamage: " << Squad[num].weapon.damage << "\nFire Time: " << Squad[num].weapon.firetime << "\nMax Ammo: " << Squad[num].weapon.maxammo << "\nGrenade Amount: " << Squad[num].grenade.maxammo << "\nGrenade Type: " << Squad[num].grenade.grenadeType << "\nMax. Health: " << Squad[num].maxhealth << "\nMax. Armor: " << Squad[num].maxarmor << "\nStarting Armor: " << Squad[num].armor << "\n\n\n";
			else
				std::cout << "\n\nThis soldier is dead.";
		break;
		case '4':
			num = 3;
			if (!Squad[num].isDead)
				std::cout << "Soldier " << num + 1 << ": " << Squad[num].type << "\nWeapon: " << Squad[num].weapon.weaponName << "\nDamage: " << Squad[num].weapon.damage << "\nFire Time: " << Squad[num].weapon.firetime << "\nMax Ammo: " << Squad[num].weapon.maxammo << "\nGrenade Amount: " << Squad[num].grenade.maxammo << "\nGrenade Type: " << Squad[num].grenade.grenadeType << "\nMax. Health: " << Squad[num].maxhealth << "\nMax. Armor: " << Squad[num].maxarmor << "\nStarting Armor: " << Squad[num].armor << "\n\n\n";
			else
				std::cout << "\n\nThis soldier is dead.";
		break;
		default:
			std::cout << "\n\nAborted.";	//player pressed anything other than 1-4, abort.
		break;
		}
	}
}