

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H

#include "../System.h"

namespace RenderSystem{
    
#define RENDER_MASK (COMPONENT_POSITION|COMPONENT_TEXTURE)
    
    void render_texture(unsigned int entity){
        auto texture_component = Entity::texture[entity];
        auto position_component = Entity::position[entity];
        
        texture_component.destignation_rect.x = (int) position_component.pos.x;
        texture_component.destignation_rect.y = (int) position_component.pos.y;
        SDL_RenderCopy(Game::renderer, texture_component.texture, NULL, &texture_component.destignation_rect);
    }
    
    void render_txmap(unsigned int entity){
        int texture_width = Entity::tx_dimensions[Entity::texture[entity].texture_id].w;
        int tiles_in_row = texture_width / TILE_SIZE, tile_id;
        SDL_Rect src_rect, dst_rect;
        
        for(int i = 0; Entity::maps[entity].t[i][0] > 0; i++){
            for(int j = 0; Entity::maps[entity].t[i][j] > 0; j++){
                tile_id = Entity::maps[entity].t[i][j] - 1;
                
                int row = tile_id / tiles_in_row;
                int col = tile_id - (row * tiles_in_row);
                
                src_rect.x = col * TILE_SIZE;
                src_rect.y = row * TILE_SIZE;
                
                dst_rect.x = j * TILE_SIZE;
                dst_rect.y = i * TILE_SIZE;

                src_rect.w = src_rect.h = dst_rect.w = dst_rect.h = TILE_SIZE;
                SDL_RenderCopy(Game::renderer, Entity::texture[entity].texture, &src_rect, &dst_rect);
            }
        }
    }
    
    void render_txmapx(unsigned int entity){
        int texture_width = Entity::tx_dimensions[Entity::texture[entity].texture_id].w;
        int tiles_in_row = texture_width / TILE_SIZE, tile_id;
        SDL_Rect src_rect, dst_rect;
        
        for(int i = 0; Entity::maps[entity].t[i][0] > 0; i++){
            for(int j = 0; Entity::maps[entity].t[i][j] > 0; j++)                
                SDL_RenderCopy(
                Game::renderer,
                Entity::texture[entity].texture,
                &Entity::maps[entity].src_rect[i][j],
                &Entity::maps[entity].dst_rect[i][j]);
        }
    }
    
    void render(){
        
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if((Entity::mask[entity] & RENDER_MASK) == RENDER_MASK){
                if((Entity::mask[entity] & COMPONENT_TXMAP) == COMPONENT_TXMAP)
                    render_txmap(entity);
                else
                    render_texture(entity);
                
            }
        }
    };
    
};


#endif
