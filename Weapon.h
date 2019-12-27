//
// Created by kira607 on 25.11.2019.
//

#include <string>
#include "functions.h"

#ifndef TXTRPG_WEAPON_H
#define TXTRPG_WEAPON_H

struct Sword
{
	std::string name = "Sword";
	int level;
	int damage;
	int reqManna = 0;
};


class Weapon
{
private:
	bool isEmpty;
	std::string name;
	short level;
	int damageMin;
	int damageMax;
	int reqManna;
	
public:
	Weapon();
	int getDamage();
	std::string getName();
	void setLvl();
	int  getLvl();
	bool isEmptyF();
	void setLvl(int lvl);
	void iAm(Wpn wpn); //???
};


#endif //TXTRPG_WEAPON_H
