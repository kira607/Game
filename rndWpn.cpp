#include <ctime>
#include "functions.h"

Wpn rndWpn(short classOfHero, short lvlOfHero)
{
	Wpn result;
	/*
	short classOfWpn;
	short typeOfWpn;
	std::string nameOfWnp;
	short lvlOfWpn;
	int minDamageOfWpn;
	int maxDamageOfWpn;
	int reqMannaWpn;
	*/
	srand(time(nullptr));
	
	switch(classOfHero)
	{
		case 1: //Warrior
		result.classOfWpn = 1;
		result.typeOfWpn = 1 + rand() % 4;
		
		switch(typeOfWpn)
		{
			case 0:
			result.name = "Hands";
			break;
			case 1:
			result.name = "Knife";
			break;
			case 2:
			result.name = "Axe";
			break;
			case 3:
			result.name = "Mace";
			break;
			case 4:
			result.name = "Sword";
			break;
		}
		
		if(lvlOfHero > 2)
		result.lvlOfWpn = (lvlOfHero - 2) + rand() % 4
		else
		result.lvlOfWpn = lvlOfHero + rand() % 1;
	
		result.minDamageOfWpn = result.typeOfWpn + 1 + result.lvlOfWpn;
		switch(typeOfWpn)
		{
			case 1:
			result.maxDamageOfWpn = result.minDamageOfWpn + 2;
			break;
			case 2:
			result.maxDamageOfWpn = result.minDamageOfWpn + 3;
			break;
			case 3:
			result.maxDamageOfWpn = result.minDamageOfWpn + 4;
			break;
			case 4:
			result.maxDamageOfWpn = result.minDamageOfWpn + 2;
			break;
		}
		result.reqMannaWpn = 0;
		break;
	}
	
	return result;
}