#ifndef ECS_CPHYSICS_HPP
#define ECS_CPHYSICS_HPP

class CPhysics : public component
{
public:
    CPosition* cPosition{nullptr};
    float vY{0};
    static constexpr float maxV{5};
    void update(float mFT) override
    {
        vY -= 5*mFT;
        cPosition->setXY(0,cPosition->y() + (vY*mFT));
        if(cPosition->y() <= 0)
        {
            vY = 5;
        }
    }
    void draw() override
    {
        log(cPosition->y());
    }
};

#endif // ECS_CPHYSICS_HPP
