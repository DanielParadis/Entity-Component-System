#ifndef ECS_CPOSITION_HPP
#define ECS_CPOSITION_HPP

class CPosition : public component
{
private:
    float X;
    float Y;
public:
    CPosition(float x, float y)
    {
        X = x;
        Y = y;
    }
    void setXY(float x, float y)
    {
        X = x;
        Y = y;
    }
    float x()
    {
        return X;
    }
    float y()
    {
        return Y;
    }
};

#endif
