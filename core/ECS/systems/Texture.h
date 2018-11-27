
#ifndef GAMEENGINE_TEXTURE_H
#define GAMEENGINE_TEXTURE_H

#pragma once

#include "../System.h"
#include "../Entity.h"
#include "Render.h"
#include "../../Game.h"
#include <fstream>

namespace TextureSystem{
    
    void load_texture(std::string *texture_path){
        SDL_Surface *load_file = SDL_LoadBMP(&(Game::project_path + *texture_path)[0]);
        auto texture = SDL_CreateTextureFromSurface(Game::renderer, load_file);
        Entity::textures.emplace_back(texture);
        SDL_FreeSurface(load_file);
    }
    
    void set_texture(unsigned int entity, unsigned int texture_id){
        if((Entity::mask[entity] & COMPONENT_TEXTURE) != COMPONENT_TEXTURE)
            Entity::mask[entity] |= Component::COMPONENT_TEXTURE;

        Entity::texture[entity].texture = Entity::textures[texture_id];
        Entity::texture[entity].texture_id = texture_id;
        if((Entity::mask[entity] & COMPONENT_SIZE) == COMPONENT_SIZE){
             Entity::texture[entity].destignation_rect.w = Entity::size[entity].w;
             Entity::texture[entity].destignation_rect.h = Entity::size[entity].h;
        } 
    }
}

#endif