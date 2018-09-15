

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H

#include "../System.h"

namespace RenderSystem{
    
#define RENDER_MASK (COMPONENT_POSITION|COMPONENT_TEXTURE)
    
    void render(){
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if((Entity::mask[entity] & RENDER_MASK) == RENDER_MASK){
                auto texture_component = Entity::texture[entity];
                auto position_component = Entity::position[entity];
                
                texture_component.destignation_rect.x = (int) position_component.pos.x;
                texture_component.destignation_rect.y = (int) position_component.pos.y;
                SDL_RenderCopy(Game::renderer, texture_component.texture, NULL, &texture_component.destignation_rect);
            }
        }
    };
    
    void load_texture(unsigned int entity, std::string *texture_path){
        SDL_Surface *load_file = SDL_LoadBMP(&(Game::project_path + *texture_path)[0]);
        Entity::texture[entity].texture = SDL_CreateTextureFromSurface(Game::renderer, load_file);
        SDL_FreeSurface(load_file);
        SDL_QueryTexture(
            Entity::texture[entity].texture,
            NULL,
            NULL,
            &Entity::texture[entity].destignation_rect.w,
            &Entity::texture[entity].destignation_rect.h
        );
    }
    
    
};


#endif
