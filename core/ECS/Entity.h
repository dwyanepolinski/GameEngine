

#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

// tu można wjebac custom allocatory do vectorów
#include "../Game.h"


namespace Entity{

    std::vector<std::string> name(ENTITY_COUNT);
    std::vector<int> mask(ENTITY_COUNT);
    
    std::vector<Position> position(ENTITY_COUNT);
    std::vector<Displacement> displacement(ENTITY_COUNT);
    std::vector<Size> size(ENTITY_COUNT);
    std::vector<Texture> texture(ENTITY_COUNT);
    std::vector<Collision> collision(ENTITY_COUNT);
    
    int master = -1;
    
    std::vector<SDL_Texture*> textures;
    std::vector<Map> maps(ENTITY_COUNT);
    
    
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
    
    int search_entity(std::string _name){
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++)
            if(name[entity] == _name)
                return entity;
        return -1;
    }
    
}

#endif
