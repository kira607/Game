//
// Created by kira607 on 25.11.2019.
//

#include "Weapon.h"
#include <string>

Weapon::Weapon()
{
    name = "Hands";
	isEmpty = true;
	level = 0;
	damage = 5;
	reqManna = 0;
}

void Weapon::setLvl(int lvl)
{
	level = lvl;
}

int Weapon::getLvl()
{
    return level;
}

bool Weapon::isEmptyF()
{
	return isEmpty;
}

int Weapon::getDamage()
{
    return damage;
}

std::string Weapon::getName()
{
    return name;
}

void Weapon::iAm(Wpn wpn)
{
	if(wpn.classOfWpn != 0)
	isEmpty = false;
	name = wpn.nameOfWpn;
	level = wpn.lvlOfWpn;
	damageMin = wpn.minDamageOfWpn;
	damageMax = wpn.maxDamageOfWpn;
	reqManna = wpm.reqManna;
}
