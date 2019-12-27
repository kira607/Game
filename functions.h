#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "Warrior.h"
//#include "Wizard.h"

#ifndef TXTRPG_WPN_STRCT
#define TXTRPG_WPN_STRCT

typedef struct tagWeapon
{
	short classOfWpn;
	short typeOfWpn;
	std::string nameOfWnp;
	short lvlOfWpn;
	int minDamageOfWpn;
	int maxDamageOfWpn;
	int reqMannaWpn;
}Wpn;

/*
classes:
1 - Warrior;
2 - Wizard;
types:
1.0 - Hands;
1.1 - Sword;
1.2 - Axe;
1.3 - Mace;
1.4 - Knife;

2.0 - Hands;
2.1 - Staff;
2.2 - Magic wand;
2.3 - Spell;

lvls:
hands - lvl of player;
other +- 2 lvl of player;

damage:
optional;

reqManna:
for Warrior 0
for Wizzard optional
*/

#endif //TXTRPG_WPN_STRCT

#ifndef TXTRPG_FUNCS_H
#define TXTRPG_FUNCS_H

template <typename T> void input(T* in);
Wpn rndWpn(short classOfHero, short lvlOfHero);

#endif //TXTRPG_FUNCS_H