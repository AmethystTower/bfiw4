#include "main.hpp"

//By Amethyst Tower

int main()
{
	//\t stands for "tab" - \n stands for "newline
	std::cout << "\t  ******      ********    **   **          **          **    *** \n";
	std::cout << "\t  **   **     **          **    **        ****        **   ** ** \n";
	std::cout << "\t  **    **    **          **     **      **  **      **   **  ** \n";
	std::cout << "\t  *******     ********    **      **    **    **    **   **   ** \n";
	std::cout << "\t  **    **    **          **       **  **      **  **   ******** \n";
	std::cout << "\t  **     **   **          **        ****        ****          ** \n";
	std::cout << "\t  ********    **          **         **          **           ** \n";
	std::cout << "\t  ______________________________________________________________ \n\n";

	std::cout << "Welcome to Battles from IW4.\n\nThis is a small, turn based game that will let you choose a squad of soldiers from different types of classes and have them fight through random types of enemies in cinematic videos recorded on the MW2:R project.\n\n";
	std::cout << "Goal: Survive 5 enemies + the boss battle to reach the end cinematic.\n\n" << "Choose one of the following options to continue:";

	//std::cout << "\n\n1: Start new game." << "\n2: Visit game's video gallery." << "\n3: Visit game's soundtracks." << "\n4: Check out the MW2:R project." << "\nAny: Quit.\n\n";
	std::cout << "\n\n1: Start new game." << "\nAny: Quit.\n\n";

	character = _getch();

	switch (character)
	{
	case '1':
		SetupGame();
	break;
	case '2':
		EndCinematic();
	break;
	case '3':
		//
	break;
	case '4':
		//
	break;
	default:
		return 0;
	break;
	}
}

void SetupGame()
{
	char buttons[4];

	for (int i = 0; i < 4; i++)
	{
		system("cls");
		//draws the soldier types.
		std::cout << "\nSoldier 1: " << Squad[0].type << "\nSoldier 2: " << Squad[1].type << "\nSoldier 3: " << Squad[2].type << "\nSoldier 4: " << Squad[3].type << "\n";

		std::cout << "\nChoose 4 soldiers from the following 8 classes by pressing the respective key.";

		std::cout << "\n\nChoose Soldier " << i+1 << ": ";

		std::cout << "\n\n______________________________________________________________";

		//assault class info
		std::cout << "\n\nClass 1: Assault [Press: A]";
		//grab the struct info from the function.
		temp = AddSoldier("assault");
		//print the info from the struct.
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Default class. Average at everything.";

		//special ops class info
		std::cout << "\n\nClass 2: Special Ops [Press: S]";
		temp = AddSoldier("special_ops");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Good damage & ammo supply. Comes with 3 concussion grenades.";

		//cqb class info
		std::cout << "\n\nClass 3: CQB [Press: C]";
		temp = AddSoldier("cqb");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Has exceptional sustainability and survivability, but is useless against air support.";

		//support class info
		std::cout << "\n\nClass 4: Support [Press: T]";
		temp = AddSoldier("support");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Decent survivability and lots of ammo, strong against all types of soldiers but has no grenades.";

		//demolition class info
		std::cout << "\n\nClass 5: Demolitions Expert [Press: D]";
		temp = AddSoldier("demolitions");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Very powerful and annihilates everything, but runs out of ammo quickly. A must-have against air support.";

		//scout class info
		std::cout << "\n\nClass 6: Scout Sniper [Press: N]";
		temp = AddSoldier("scout");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: High risk, high reward. Powerful against normal soldiers, but weak against everything else. Comes with 3 throwing knives.";

		//marksman class info
		std::cout << "\n\nClass 7: Marksman [Press: R]";
		temp = AddSoldier("marksman");
		std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Has very high damage per second. Strong against all enemies but comes with a high ammo consumption against vehicles.";

		//juggernaut class info - draw only when available.
		if( juggernautAvailable )
		{
			std::cout << "\n\nClass 8: Juggernaut [Press: J]";
			temp = AddSoldier("juggernaut");
			std::cout << "\nWeapon: " << temp.weapon.weaponName << "\nDamage: " << temp.weapon.damage << "\nFire Time: " << temp.weapon.firetime << "\nMax Ammo: " << temp.weapon.maxammo << "\nGrenade Amount: " << temp.grenade.maxammo << "\nGrenade Type: " << temp.grenade.grenadeType << "\nMax. Health: " << temp.maxhealth << "\nMax. Armor: " << temp.maxarmor << "\nStarting Armor: " << temp.armor << "\nDescription: Powerful class that is exceptional at everything. Limited to 1 per game and has no health regeneration.";
		}

		character = _getch();

		character = tolower(character);

		switch (character)
		{
		case 'a':
			Squad[i] = AddSoldier("assault");
		break;
		case 's':
			Squad[i] = AddSoldier("special_ops");
		break;
		case 'c':
			Squad[i] = AddSoldier("cqb");
		break;
		case 't':
			Squad[i] = AddSoldier("support");
		break;
		case 'd':
			Squad[i] = AddSoldier("demolitions");
		break;
		case 'n':
			Squad[i] = AddSoldier("scout");
		break;
		case 'r':
			Squad[i] = AddSoldier("marksman");
		break;
		case 'j':
			if (juggernautAvailable)
			{
				Squad[i] = AddSoldier("juggernaut");
				juggernautAvailable = false;
			}
			else
				i--;
		break;
		default:
			i--;
		break;
		}
		buttons[i] = character;
	}

	StartGame();
}

void StartGame()
{
	system("cls");

	std::cout << "\nYou've chosen your soldiers! Let the game begin...\n\n\nGood luck!\n\n";
	system("pause");

	for (int i = 0; i < 4; i++)
		std::cout << "\nSoldier " << i+1 << ": " << Squad[i].type << "\nWeapon: " << Squad[i].weapon.weaponName << "\nDamage: " << Squad[i].weapon.damage << "\nFire Time: " << Squad[i].weapon.firetime << "\nMax Ammo: " << Squad[i].weapon.maxammo << "\nGrenade Amount: " << Squad[i].grenade.maxammo << "\nGrenade Type: " << Squad[i].grenade.grenadeType << "\nMax. Health: " << Squad[i].maxhealth << "\nMax. Armor: " << Squad[i].maxarmor << "\nStarting Armor: " << Squad[i].armor << "\n\n";

	std::cout << "\nTake a look at your soldiers and press any key when you're ready.\n\n";

	//viewing soldier stats manually is pretty buggy at the moment. maybe it will be fixed someday when I gain the motivation to do so, but probably not :D
	//I mostly did this to get more used to using threads which worked quite well apart from the bugginess.
	/*
	std::cout << "\nTake a look at your soldiers and press any key when you're ready.\n\nTip: You can view their stats while outside of combat by pressing the key 'S' and then their number.\n\n";
	std::thread thread_stats(Stats::MonitorButtonStats, Squad);
	thread_stats.detach();		//detach() has to be called so that the thread can be destroyed safely.*/

	_getch();

	Wave1();
}

void EndCinematic()
{
	TCHAR szPath[] = TEXT("..\\videos\\cinematic.mp4");

	HINSTANCE hRet = ShellExecute(
	HWND_DESKTOP,   //The window that is displayed when the file is missing.
	TEXT("open"),   //The action that should be executed.
	szPath,         //The path.
	NULL,           //Parameters
	NULL,           //Default directory
	SW_SHOW);       //How to open the file

	if ((LONG)hRet <= 32)	//this counts the length of the chars. if it can't find the video file, the path will return 0 and result in less than 32 characters.
	{
		//display an error message that the file couldn't be found.
		MessageBox(HWND_DESKTOP, TEXT("Folder must be called bfiw4!"), TEXT(""), MB_OK);

	}
}