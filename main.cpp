#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <time.h>
#include "log.hpp"
#include "ECS/ECS.hpp"

manager Manager;
entity& createVirtualBall()
{
    entity& E(Manager.addEntity());
    E.addComponent<CPosition>(0,0);
    E.addComponent<CPhysics>();
    auto& cPhys = E.getComponent<CPhysics>();
    cPhys.cPosition = &E.getComponent<CPosition>();
    return E;
}

void gameLoop()
{
    auto& Test = createVirtualBall();
    float mFT = 0.0001;
    while(true)
    {
        time_t timeStart = clock();
        Manager.refresh();
        Manager.update(mFT);
        Manager.draw();
        while(clock() - timeStart <= (float)CLOCKS_PER_SEC/10){}
        mFT = 1.0f/10.0f;
    }
}

int main(int argc, char** argv)
{
    gameLoop();
    return 0;
}
