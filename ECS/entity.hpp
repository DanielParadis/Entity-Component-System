#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

/*
We are defining the entity class. The entity class will be a container
that holds a vector of components. Components are what will run the entity.

We will need a vector of components
A method to add components
A method to delete components
A method to delete the entity
A method to update the components
A method to display the components
*/

class entity
{
private:
    std::vector<component*> components;
    bool alive = true;
    bool bitSetArray[ECS_MAX_COMPONENTS];
    component* componentArray[ECS_MAX_COMPONENTS];
public:
    // We need to a way to check if the entity has a component already
    template <typename T>
    bool hasComponent()
    {
        return bitSetArray[getComponentID<T>()];
    }
    // We need a way to add a component
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        // Checks if we already have the component
        assert(!hasComponent<T>());
        // Creates a pointer of type T and calls new
        // Then the arguments from above are passed to
        // The constructor of type t
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->myEntity = this;
        component* ptrC = c;
        // Our new component is added to the component vector
        components.emplace_back(std::move(ptrC));
        // We set our bitset to true;
        componentArray[getComponentID<T>()] = c;
        bitSetArray[getComponentID<T>()] = true;
        // initialize or new component
        c->init();
        return *c;
    }
    void destroy()
    {
        alive = false;
    }
    template <typename T>
    T& getComponent()
    {
        assert(hasComponent<T>());
        auto ptr(componentArray[getComponentID<T>()]);
        return *reinterpret_cast<T*>(ptr);
    }

    void update(float mFT)
    {
        for(auto& i : components)
        {
            i->update(mFT);
        }
    }

    void draw()
    {
        for(auto& i : components)
        {
            i->draw();
        }
    }
    bool isAlive()
    {
        return alive;
    }
};

#endif
