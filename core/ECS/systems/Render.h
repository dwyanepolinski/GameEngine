

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H

#include "../System.h"

#define RENDER_MASK (COMPONENT_POSITION|COMPONENT_TEXTURE)

class RenderSystem : public System{
    
    void update(Entity::mask) override{
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if(mask[entity] & RENDER_MASK == RENDER_MASK){
                
            }
        }
    };
    
    
};


#endif
