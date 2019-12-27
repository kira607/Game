//
// Created by kira607 on 25.11.2019.
//

#include <iostream>
#include <ctime>
#include <string>
#include <climits>

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
class Weapon
{
private:
	bool isEmpty;
	short classW;
	short type;
	std::string name;
	short level;
	int damageMin;
	int damageMax;
	int reqManna;

public:
	Weapon();

	bool getIsEmpty();
	short getClassW();
	short getType();
	std::string getName();
	int getLevel();
	int getMinDamage();
	int getMaxDamage();
	int getReqManna();

	void setIsEmpty(bool);
	void setClassW(short);
	void setType(short);
	void setName(std::string);
	void setLevel(int);
	void setMinDamage(int);
	void setMaxDamage(int);
	void setReqManna(int);

	void setFullWeapon(bool, short, short, std::string, short, int, int, int);
	void iAm(Weapon weapon);
};

class Hero
{
private:
	std::string nameOfClass = "Hero";
	const int maxLevel = 100;
	int level; // lvl of Hero
	int health; //Current lvl of health
	int maxHealth; // Max lvl of health
	int experience; //Current lvl of exp
	int maxExperience; //Max lvl of exp
	int minDamage;
	int maxDamage;
	int manna;
	Weapon weapon;

public:
	Hero();

	int getLvl();
	int getHealth();
	int getMaxHealth();
	int getExp();
	int getMaxExp();
	int getMinDamage();
	int getMaxDamage();

	void levelUp();
	void printStats();
	void addExp(int exp);
	void reduceHealth(int reduce);
	void pickUp(Weapon weapon);
	void update();
};

class Warrior : public Hero
{
private:
	const std::string nameOfClass = "Warrior";
	const int maxLevel = 100;
	int level; // lvl of Hero
	int health; //Current lvl of health
	int maxHealth; // Max lvl of health
	int experience; //Current lvl of exp
	int maxExperience; //Max lvl of exp
	int minDamage;
	int maxDamage;
	Weapon weapon;

public:
	Warrior();

	int getLvl();
	int getHealth();
	int getMaxHealth();
	int getExp();
	int getMaxExp();
	int getMinDamage();
	int getMaxDamage();

	void levelUp();
	void printStats();
	void addExp(int exp);
	void reduceHealth(int reduce);
	void pickUp(Weapon weapon);
	void update();
};

class Wizard
{
private:
	const std::string nameOfClass = "Wizard";
	const int maxLevel = 100;
	int level; // lvl of Hero
	int health; //Current lvl of health
	int maxHealth; // Max lvl of health
	int experience; //Current lvl of exp
	int maxExperience; //Max lvl of exp
	int minDamage;
	int maxDamage;
	int manna;
	Weapon weapon;

public:
	Wizard();

	int getLvl();
	int getHealth();
	int getMaxHealth();
	int getExp();
	int getMaxExp();
	int getMinDamage();
	int getMaxDamage();

	void levelUp();
	void printStats();
	void addExp(int exp);
	void reduceHealth(int reduce);
	void pickUp(Weapon weapon);
	void update();
};

template <class T> void input(T* in);
Weapon randWeapon(short classOfHero, short lvlOfHero);

int main()
{
	short classOfHero;
	short* ptr = &classOfHero;
	std::cout << "Choose class of Hero:" << std::endl;
	std::cout << "1: Warrior" << std::endl;
	std::cout << "2: Wizard" << std::endl;

	do
	{
		std::cout << "Input:";
		input<short>(ptr);
	} while (classOfHero > 2 || classOfHero < 1);

	if(classOfHero == 1)
	Warrior hero;
	if(classOfHero == 2)
	Wizard hero;

	hero.printStats();
	hero.addExp(55);
	hero.update();
	hero.printStats();

	Weapon weapon;
	weapon = randWeapon(classOfHero, hero.getLvl());
	hero.pickUp(weapon);
	hero.printStats();

	std::cin.get();
	return 0;
}

template <class T> void input(T* in)
{
	while (true)
	{
		std::cin >> *in;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

template <class T> void input(T* in)
{
	while (true)
	{
		std::cin >> *in;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

Weapon randWeapon(short classOfHero, short lvlOfHero)
{
	Weapon result;

	srand(time(nullptr));

	switch (classOfHero)
	{
	case 1: //Warrior
		result.setClassW(1);
		result.setType(1 + (rand() % 4));

		switch (result.getType())
		{
		case 0:
			result.setName("Hands");
			result.setIsEmpty(true);
			break;
		case 1:
			result.setName("Knife");
			result.setIsEmpty(false);
			break;
		case 2:
			result.setName("Axe");
			result.setIsEmpty(false);
			break;
		case 3:
			result.setName("Mace");
			result.setIsEmpty(false);
			break;
		case 4:
			result.setName("Sword");
			result.setIsEmpty(false);
			break;
		}

		if (lvlOfHero > 2)
			result.setLevel((lvlOfHero - 2) + rand() % 4);
		else
			result.setLevel(lvlOfHero + rand() % 1);

		result.setMinDamage(result.getType() + 1 + result.getLevel());
		switch (result.getType())
		{
		case 1:
			result.setMaxDamage(result.getMinDamage() + 2);
			break;
		case 2:
			result.setMaxDamage(result.getMinDamage() + 3);
			break;
		case 3:
			result.setMaxDamage(result.getMinDamage() + 4);
			break;
		case 4:
			result.setMaxDamage(result.getMinDamage() + 2);
			break;
		}
		result.setReqManna(0);
		break;
	}

	return result;
}

// WARRIOR METODS //

Warrior::Warrior()
{
	srand(time(nullptr));
	level = 1;

	health = 13 + rand() % 6;
	maxHealth = health;

	experience = 0;
	maxExperience = 50;

	minDamage = weapon.getMinDamage();
	maxDamage = weapon.getMaxDamage();
	weapon.setLevel(level);
}

int Warrior::getLvl()
{
	return level;
}
int Warrior::getHealth()
{
	return health;
}
int Warrior::getMaxHealth()
{
	return maxHealth;
}
int Warrior::getExp()
{
	return experience;
}
int Warrior::getMaxExp()
{
	return maxExperience;
}
int Warrior::getMinDamage()
{
	return minDamage;
}
int Warrior::getMaxDamage()
{
	return maxDamage;
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
	std::cout << "WPN: " << weapon.getName() << ' ' << "LVL:" << weapon.getLevel() << std::endl;
	std::cout << "HP: " << getHealth() << '/' << maxHealth << '\t';
	std::cout << "EXP: " << getExp() << '/' << maxExperience << '\t';
	std::cout << "DMG: " << getMinDamage() << " - " << getMaxDamage() << std::endl;;
}

void Warrior::levelUp()
{
	std::cout << "LEVEL UP!" << std::endl;
	if (level < maxLevel)
	{
		++level;
	}
	srand(time(nullptr));
	maxHealth += 4 + rand() % 3;
	health = maxHealth;

	experience -= maxExperience;
	maxExperience += 10;

	++minDamage;
	++maxDamage;
}

void Warrior::update()
{
	if (health <= 0)
		std::cout << "You are dead!" << std::endl;
	if (experience >= maxExperience)
		levelUp();
}

void Warrior::pickUp(Weapon weaponIn)
{
	weapon.iAm(weaponIn);
	minDamage += weaponIn.getMinDamage();
	maxDamage += weaponIn.getMaxDamage();
}

// WIZARD METODS //

Wizard::Wizard()
{
	srand(time(nullptr));
	level = 1;

	health = 13 + rand() % 6;
	maxHealth = health;

	experience = 0;
	maxExperience = 50;

	minDamage = weapon.getMinDamage();
	maxDamage = weapon.getMaxDamage();

	manna = 50;

	weapon.setLevel(level);
}

int Wizard::getLvl()
{
	return level;
}
int Wizard::getHealth()
{
	return health;
}
int Wizard::getMaxHealth()
{
	return maxHealth;
}
int Wizard::getExp()
{
	return experience;
}
int Wizard::getMaxExp()
{
	return maxExperience;
}
int Wizard::getMinDamage()
{
	return minDamage;
}
int Wizard::getMaxDamage()
{
	return maxDamage;
}

void Wizard::addExp(int exp)
{
	experience += exp;
}

void Wizard::reduceHealth(int reduce)
{
	health -= reduce;
}

void Wizard::printStats()
{
	std::cout << "=STATS=" << std::endl;
	std::cout << "CLS: " << nameOfClass << '\t' <<
		"LVL: " << level << '/' << maxLevel << std::endl;
	std::cout << "WPN: " << weapon.getName() << ' ' << "LVL:" << weapon.getLevel() << std::endl;
	std::cout << "HP: " << getHealth() << '/' << maxHealth << '\t';
	std::cout << "EXP: " << getExp() << '/' << maxExperience << '\t';
	std::cout << "DMG: " << getMinDamage() << " - " << getMaxDamage() << std::endl;;
}

void Wizard::levelUp()
{
	std::cout << "LEVEL UP!" << std::endl;
	if (level < maxLevel)
	{
		++level;
	}
	srand(time(nullptr));
	maxHealth += 4 + rand() % 3;
	health = maxHealth;

	experience -= maxExperience;
	maxExperience += 10;

	++minDamage;
	++maxDamage;
}

void Wizard::update()
{
	if (health <= 0)
		std::cout << "You are dead!" << std::endl;
	if (experience >= maxExperience)
		levelUp();
}

void Wizard::pickUp(Weapon weaponIn)
{
	weapon.iAm(weaponIn);
	minDamage += weaponIn.getMinDamage();
	maxDamage += weaponIn.getMaxDamage();
}

//WEAPON METHODS

Weapon::Weapon()
{
	isEmpty = true;
	classW = 1;
	type = 0;
	name = "Hands";
	level = 1;
	damageMin = 4;
	damageMax = 5;
	reqManna = 0;
}

bool Weapon::getIsEmpty()
{
	return isEmpty;
}
short Weapon::getClassW()
{
	return classW;
}
short Weapon::getType()
{
	return type;
}
std::string Weapon::getName()
{
	return name;
}
int Weapon::getLevel()
{
	return level;
}
int Weapon::getMinDamage()
{
	return damageMin;
}
int Weapon::getMaxDamage()
{
	return damageMax;
}
int Weapon::getReqManna()
{
	return reqManna;
}

void Weapon::setIsEmpty(bool isEmptyIn)
{
	isEmpty = isEmptyIn;
}
void Weapon::setClassW(short classWIn)
{
	classW = classWIn;
}
void Weapon::setType(short typeIn)
{
	type = typeIn;
}
void Weapon::setName(std::string nameIn)
{
	name = nameIn;
}
void Weapon::setLevel(int levelIn)
{
	level = levelIn;
}
void Weapon::setMinDamage(int minDamageIn)
{
	damageMin = minDamageIn;
}
void Weapon::setMaxDamage(int maxDamageIn)
{
	damageMax = maxDamageIn;
}
void Weapon::setReqManna(int reqMannaIn)
{
	reqManna = reqMannaIn;
}

void Weapon::setFullWeapon(bool isEmptyIn,
	short classWIn,
	short typeIn,
	std::string nameIn,
	short levelIn,
	int minDamageIn,
	int maxDamageIn,
	int reqMannaIn)
{
	isEmpty = isEmptyIn;
	classW = classWIn;
	type = typeIn;
	name = nameIn;
	level = levelIn;
	damageMin = minDamageIn;
	damageMax = maxDamageIn;
	reqManna = reqMannaIn;
}

void Weapon::iAm(Weapon weaponIn)
{
	if (weaponIn.getType() != 0)
	{
		isEmpty = false;
		classW = weaponIn.getClassW();
		type = weaponIn.getType();
		name = weaponIn.getName();
		level = weaponIn.getLevel();
		damageMin = weaponIn.getMinDamage();
		damageMax = weaponIn.getMaxDamage();
		reqManna = weaponIn.getReqManna();
	}

}