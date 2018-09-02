

#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

// tu można wjebac custom allocatory do vectorów

#define ENTITY_COUNT 20

#include "Component.h"
#include <vector>


namespace Entity{

    std::vector<int> mask;
    
    std::vector<Position> position;
    std::vector<Displacement> displacement;
    std::vector<Size> size;
    std::vector<Texture> texture;
    
//     mask.reserve(ENTITY_COUNT);
//     position.reserve(ENTITY_COUNT);
//     displacement.reserve(ENTITY_COUNT);
//     size.reserve(ENTITY_COUNT);
//     texture.reserve(ENTITY_COUNT);
    
    
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
