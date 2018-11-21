

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H


#pragma once
#include "../Entity.h"


namespace RenderSystem{
    
#define RENDER_MASK (COMPONENT_POSITION|COMPONENT_TEXTURE)
    
    void render_texture(unsigned int entity){
        auto texture_component = Entity::texture[entity];
        auto position_component = Entity::position[entity];
        
        texture_component.destignation_rect.x = (int) position_component.pos.x;
        texture_component.destignation_rect.y = (int) position_component.pos.y;
        SDL_RenderCopy(Game::renderer, texture_component.texture, NULL, &texture_component.destignation_rect);
    }
    
    void render(){
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if((Entity::mask[entity] & RENDER_MASK) == RENDER_MASK)
                render_texture(entity);
        }
    };
    
};

#endif
