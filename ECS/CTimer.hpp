#ifndef ECS_CTIMER_HPP
#define ECS_CTIMER_HPP


class CTimer : public component
{
private:
    int counter{100};
public:
    void update(float mFT) override
    {
        --counter;
        if(counter <= 0)
        {
            myEntity->destroy();
        }
    }
    void draw() override
    {
        log(counter);
    }
    CTimer(int n)
    {
        counter = n;
    }
    CTimer(){}
};

#endif // ECS_CTIMER_HPP
