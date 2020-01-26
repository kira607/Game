#include "Creature.h"


class Enemy : public Creature
{
private:

public:
    Hitbox attack() override
    {
        Hitbox result;
        Hitbox.rotate(m_rotation);
    }

    void move() override
    {

    }
};