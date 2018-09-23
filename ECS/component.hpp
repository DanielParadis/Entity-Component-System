#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP


/*
We are creating a function that generates a unique number every time it is called.
lastID is set to static which means its value is "remembered" every time we
call it.
*/

inline std::size_t getUniqueID()
{
    static std::size_t lastID{0};
    return lastID++;
}

/*
The template function below is pretty special. Creating typeID
as a static variable means that it is remembered across all calls.
Static variables can only be initialized once, which means it receives
a unique ID once from the above function and it retains this value through
the rest of execution.
*/

template<typename T>
inline std::size_t getComponentID()
{
    static std::size_t typeID{getUniqueID()};
    return typeID;
}

/*
We are making a base component class. Things to consider is that all components
will have:
init
update
draw
destructor
*/

class component
{
public:
    entity* myEntity;
    virtual void init(){}
    virtual void update(float mFT){}
    virtual void draw(){}
    virtual ~component(){}
};


#endif
