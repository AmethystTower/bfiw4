#include "Combat.hpp"

int ChooseSoldier()
{
	system("cls");

	std::cout << "\n\nWhich soldier would you like to choose for combat?\n\n";

		for (int i = 0; i < 4; i++)
		{
			if( !Squad[i].isDead )
				std::cout << "Soldier " << i + 1 << ": " << Squad[i].type << "\nWeapon: " << Squad[i].weapon.weaponName << "\nDamage: " << Squad[i].weapon.damage << "\nFire Time: " << Squad[i].weapon.firetime << "\nMax Ammo: " << Squad[i].weapon.maxammo << "\nGrenade Amount: " << Squad[i].grenade.maxammo << "\nGrenade Type: " << Squad[i].grenade.grenadeType << "\nHealth: " << Squad[i].health << "\nArmor: " << Squad[i].armor << "\n\n\n";
			else
				std::cout << "Soldier " << i + 1 << ": " << Squad[i].type << "\nStatus: " << Squad[0].status << "\n\n\n";
		}

	for (;;)
	{
		char chosenSoldier = _getch();
		chosenSoldier = tolower(chosenSoldier);

		switch (chosenSoldier)
		{
		case '1':
			if (!Squad[0].isDead)
				return 0;
			else
				std::cout << "\n\nThis soldier is dead. Take another one!";
			break;
		case '2':
			if (!Squad[1].isDead)
				return 1;
			else
				std::cout << "\n\nThis soldier is dead. Take another one!";
			break;
		case '3':
			if (!Squad[2].isDead)
				return 2;
			else
				std::cout << "\n\nThis soldier is dead. Take another one!";
			break;
		case '4':
			if (!Squad[3].isDead)
				return 3;
			else
				std::cout << "\n\nThis soldier is dead. Take another one!";
			break;
		default:
			//do nothing, player must choose a soldier.
			break;
		}
	}
}

bool Combat(int PlayerSoldier, int Combatant)
{
	system("cls");

	float player_damage = 0.0f;
	float enemy_damage = 0.0f;

	std::cout << "Your " << Squad[PlayerSoldier].type << " is now fighting an enemy " << enemies[Combatant].type << "!\nMay take a few seconds for the results.\n\n\n";

	//this is the damage they deal to each other within a second, till one of them is down.
	//the player always gains an advantage and attacks first.
	for (;;)
	{
		player_damage = DealtDamagePlayer(PlayerSoldier);
		player_damage = DamageModifiers(player_damage, Squad[PlayerSoldier].weapon.weaponName, true, Squad[PlayerSoldier], enemies[Combatant]);

		//apply damage and check if enemy died. if he did, return and end combat scene.
		enemies[Combatant].health -= player_damage;
		if (enemies[Combatant].health <= 0)
		{
			std::cout << "Your soldier dealt " << player_damage << " to the enemy and won!\n\n";

			enemies[Combatant].isDead = true;
			return true;
		}
		else
			std::cout << "Your soldier dealt " << player_damage << " to the enemy!\n\n";

		enemy_damage = DealtDamageEnemy(Combatant);
		enemy_damage = DamageModifiers(enemy_damage, Squad[PlayerSoldier].weapon.weaponName, false, Squad[PlayerSoldier], enemies[Combatant]);

		//apply damage and check if player's soldier died here. update if yes and return with a loss.
		Squad[PlayerSoldier].health -= enemy_damage;
		if (Squad[PlayerSoldier].health <= 0)
		{
			std::cout << "The enemy dealt " << enemy_damage << " to your soldier and defeated one of your soldiers!\n\n";

			Squad[PlayerSoldier].isDead = true;
			Squad[PlayerSoldier].status = "Dead";
			return false;
		}
		else
			std::cout << "The enemy dealt " << enemy_damage << " to your soldier!\n\n";

		//nobody died? Sleep and repeat till someone dies.
		Sleep(1000);
	}
}

float DealtDamagePlayer(int PlayerSoldier)
{
	float damage = 0.0f;
	int shots = 0;

	//the 1 equals one second of damage per second. x += firetime till it reaches 1 (1000 milliseconds) while applying damage with each cycle.
	for (float i = 0.0f; i <= 1; i += Squad[PlayerSoldier].weapon.firetime)
	{
		damage += Squad[PlayerSoldier].weapon.damage;
		Squad[PlayerSoldier].weapon.maxammo--;

		//the player's soldier is out of ammo, abort damage phase and return the damage he dealt. if this doesn't kill off the enemy, he's dead.
		if (Squad[PlayerSoldier].weapon.maxammo <= 0)
			return damage;
	}

	return damage;
}

float DealtDamageEnemy(int Combatant)
{
	float damage = 0.0f;
	int shots = 0;

	//the 1 equals one second of damage per second. x += firetime till it reaches 1 (1000 milliseconds) while applying damage with each cycle.
	for (float i = 0; i <= 1; i += enemies[Combatant].firetime)
		damage += enemies[Combatant].damage;

	return damage;
}

float DamageModifiers(float damage, std::string weapon, bool isPlayer, soldier PlayerSoldier, enemy Combatant)
{
	if (!isPlayer)
	{
		//if the player's soldier has armor, block damage. each armor point blocks 2 damage.
		if (PlayerSoldier.armor > 0.0f)
		{
			damage -= (PlayerSoldier.armor*2);

			if (damage < 0.0f)
				damage = 0.0f;

			PlayerSoldier.armor -= (damage / 2);

			if (PlayerSoldier.armor < 0.0f)
				PlayerSoldier.armor = 0.0f;
		}
	}
	else
	{
		//damage multipliers depending on the enemy and weapon type.
		if (!Combatant.isVehicle)
		{
			if (weapon == "Anti-Tank Grenade")	//anti tank grenades deal 10% damage to non-vehicle enemies.
				damage *= 0.1f;
		}
		
		else if (Combatant.isArmored)
		{
			if (weapon == "PP90M1")				//the PP90M1 deals 90% damage to armored soldiers
				damage *= 0.9f;
		}

		else if (Combatant.isVehicle)
		{
			if (weapon != "Anti-Tank Grenade" && weapon != "AT4")	//any weapon that isn't the AT grenade or AT4 deal 50% damage.
				damage *= 0.5f;

			if (weapon == "Spas12" || weapon == "Throwing Knife")	//the SPAS12 and throwing knife deal no damage to air support.
				damage = 0.0f;
		}
	}

	return damage;
}