#include "Hitbox.h"

class Creature
{
protected:
    int m_HP, m_maxHP;
    double m_x, m_y;
    double m_rotation;
    int m_modelID;
    double m_speed;
    Hitbox m_hitbox;
public:
    Creature(int HP = 10):m_HP{HP},m_maxHP{HP}{}
    virtual Hitbox attack() = 0;
    virtual void move() = 0;
};