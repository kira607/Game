//
// Created by kira607 on 25.11.2019.
//
#include "Weapon.h"
#include <string>

#ifndef TXTRPG_WARRIOR_H
#define TXTRPG_WARRIOR_H


class Warrior
{
private:
    const std::string nameOfClass = "Warrior";
    const int maxLevel = 100;
    int level; // lvl of Hero

    int health; //Current lvl of health
    int maxHealth; // Max lvl of health

    int experience; //Current lvl of exp
    int maxExperience; //Max lvl of exp

    int damage;
	int totalDamage;
    Weapon weapon;

public:
    Warrior();
    int getHealth();
    int getDamage();
	int getExp();
	int getLvl();
	
    void setNewHealth();
    void levelUp();
    void printStats();
    void addExp(int exp);
    void reduceHealth(int reduce);
	void pickUp(Wpn wpn);
    void updateExpHP();
};


#endif //TXTRPG_WARRIOR_H
