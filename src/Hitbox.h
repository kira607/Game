

class Hitbox
{
private:
    const int width = 4, height = 3;
    double m_rotation;
    //int m_formID; //form of hitbox
    double m_size;
    int *m_matrix;
public:
    Hitbox()
    {
        m_rotation = 0;
        m_size = 1;
        m_matrix = new int[width*height];

        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                m_matrix[i*width+j] = 0;
            }
        }
    }

    ~Hitbox()
    {
        delete [] m_matrix;
    }

    void rotate(double rotation)
    {
        m_rotation += rotation;
    }

};

