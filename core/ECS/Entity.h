

#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

// tu można wjebac custom allocatory do vectorów

#define ENTITY_COUNT 20

#include "Component.h"
#include "../Game.h"
#include <vector>


namespace Entity{

    std::vector<int> mask(ENTITY_COUNT);
    
    std::vector<Position> position(ENTITY_COUNT);
    std::vector<Displacement> displacement(ENTITY_COUNT);
    std::vector<Size> size(ENTITY_COUNT);
    std::vector<Texture> texture(ENTITY_COUNT);
    
    
    int create_entity(){
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if(mask[entity] == Component::COMPONENT_NONE)
                return entity;
        }
        
        return -1;
    }
    
    void drop_entity(unsigned int entity){
        mask[entity] = Component::COMPONENT_NONE;
    }
    
}






#endif
