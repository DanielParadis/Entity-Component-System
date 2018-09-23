#ifndef ECS_MANAGER_HPP
#define ECS_MANAGER_HPP
/*
We need to create a manager to hold all of our entities.
Our entities as act as a container to hold all of our
components... Funny how this works. Anyway, we need the do the following:

construct and destruct new entities
run updates and draw functions for our entities
*/

class manager
{
private:
    std::vector<entity*> entities;

public:
    entity& addEntity()
    {
        entity* e = new entity;
        entities.emplace_back(std::move(e));
        return *e;
    }

    void refresh()
    {
        for(std::vector<entity*>::iterator i = entities.begin(); i < entities.end();)
        {
            if((*i)->isAlive() == false)
            {
                i = entities.erase(i);
            }
            else
            {
                ++i;
            }
        }
    }

    void update(float mFT)
    {
        for(auto& i : entities)
            i->update(mFT);
    }
    void draw()
    {
        for(auto& i : entities)
            i->draw();
    }
};

#endif // ECS_MANAGER_HPP
