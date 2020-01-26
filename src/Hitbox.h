

class Hitbox
{
private:
    double m_rotation;
    //int m_formID; //form of hitbox
    double m_size;
    int matrix[12];
public:
    Hitbox()
    {
        m_rotation = 0;
        m_size = 1;

        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                matrix[i*3+j] = 0;
            }
        }
    }

    void rotate(double rotation)
    {
        m_rotation += rotation;
    }

};

