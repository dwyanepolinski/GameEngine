

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H

#include "../System.h"

#define RENDER_MASK (COMPONENT_POSITION|COMPONENT_TEXTURE)

class RenderSystem : public System{
public:
    
    void update(std::vector<int> mask) override{
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if((mask[entity] & RENDER_MASK) == RENDER_MASK){
                auto texture_component = Entity::texture[entity];
                auto position_component = Entity::position[entity];
                
                texture_component.destignation_rect.x = (int) position_component.x;
                texture_component.destignation_rect.y = (int) position_component.y;
                SDL_RenderCopy(Game::renderer, texture_component.texture, NULL, &texture_component.destignation_rect);
            }
        }
    };
    
    
};


#endif
