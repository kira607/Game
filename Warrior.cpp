//
// Created by kira607 on 25.11.2019.
//

#include "Warrior.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

//Constructor
Warrior::Warrior()
{
    srand(time(nullptr));
    level = 1;

    health = 13 + rand() % 6;
    maxHealth = health;

    experience = 0;
    maxExperience = 50;

    damage = 5;
	totalDamage = damage;
	weapon.setLvl(level);
}

//Set Health
void Warrior::setNewHealth()
{
    srand(time(nullptr));
    maxHealth += 4 + rand() % 3;
    health = maxHealth;
}

void Warrior::addExp(int exp)
{
    experience += exp;
}

void Warrior::reduceHealth(int reduce)
{
    health -= reduce;
}

void Warrior::printStats()
{
    std::cout << "=STATS=" << std::endl;
    std::cout << "CLS: " << nameOfClass << '\t' <<
                 "LVL: " << level << '/' << maxLevel << std::endl;
    std::cout << "WPN: " << weapon.getName() << ' ' << "LVL:" << weapon.getLvl() << std::endl;
    std::cout << "HP: " << getHealth() << '/' << maxHealth << '\t';
    std::cout << "EXP: " << getExp() << '/' << maxExperience << '\t';
    std::cout << "DMG: " << getDamage() << std::endl;;
}

//LVL UP
void Warrior::levelUp()
{
    std::cout << "LEVEL UP!" << std::endl;
    if(level < maxLevel)
    ++level;
    setNewHealth();

    experience -= maxExperience;
    maxExperience += 10;

    ++damage;
}

void Warrior::updateExpHP()
{
    if(health <= 0)
        std::cout << "You are dead!" << std::endl;
    if(experience >= maxExperience)
        levelUp();
}

//
//  GET() FUNCTIONS
//

int Warrior::getHealth()
{
    return health;
}

int Warrior::getDamage()
{
    return damage;
}

int Warrior::getExp()
{
    return experience;
}

int Warrior::getLvl()
{
    return level;
}

void Warrior::pickUp(Wpn wpn)
{
	weapon.iAm(wpn);
	totalDamage = damage + weapon.getDamage();
}

