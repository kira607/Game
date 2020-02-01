#ifndef HITBOX_H
#define HITBOX_H

#include <Gl/glm.h>

class Hitbox
{
private:
    glm::mat4 m_mat;
public:
    Hitbox()
    {
        m_rotation = 0;
        m_size = 1;

        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                m_mat[i][j] = -100;

                if(i == height - 1)
                {
                    m_mat[i][j] = 1;
                }
            }
        }
    }

    ~Hitbox() = default;
};


#endif //HITBOX_H
