#ifndef CREATURE_H
#define CREATURE_H

#include "Hitbox.h"

class Creature
{
protected:
    int m_HP, m_maxHP;
    double m_rotation;
    int m_modelID;
    double m_speed;
    Hitbox m_hitbox;
    Hitbox m_hitboxA;
public:
    Creature(int HP = 10):m_HP{HP},m_maxHP{HP}
    {

    }
    virtual void attack() = 0;
    virtual void move() = 0;
};

#endif //CREATURE_H
