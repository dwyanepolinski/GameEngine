

#ifndef GAMEENGINE_SYSTEM_H
#define GAMEENGINE_SYSTEM_H

#include "Entity.h"
#include "Component.h"

class System{
public:
    virtual void init() = 0;
    virtual void update(Entity::mask) = 0;
    virtual void destruct() = 0;        
};

#endif
