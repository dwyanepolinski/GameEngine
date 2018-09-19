
#ifndef GAMEENGINE_TEXTURE_H
#define GAMEENGINE_TEXTURE_H

#include "../System.h"
#include <fstream>

namespace TextureSystem{
    
    void load_mapx(unsigned int entity, std::string *map_path){
        if((Entity::mask[entity] & RENDER_MASK) == RENDER_MASK){
            std::ifstream tile_map(Game::project_path + *map_path);
            std::string line;
            size_t delimeter;
            int i = 0, j, row, col;
            
            int texture_width = Entity::tx_dimensions[Entity::texture[entity].texture_id].w;
            int tiles_in_row = texture_width / TILE_SIZE, tile_id;
            
            while(tile_map >> line){
                j = 0;
                do{
                    delimeter = line.find(',');
                    tile_id = std::stoi(line.substr(0, delimeter));
                    Entity::maps[entity].t[i][j] = tile_id + 1;
                    line = line.substr(delimeter + 1);
                    
                    
                    row = tile_id / tiles_in_row;
                    col = tile_id - (row * tiles_in_row);
                    Entity::maps[entity].src_rect[i][j].x = col * TILE_SIZE;
                    Entity::maps[entity].src_rect[i][j].y = row * TILE_SIZE;
                    
                    Entity::maps[entity].dst_rect[i][j].x = j * TILE_SIZE;
                    Entity::maps[entity].dst_rect[i][j].y = i * TILE_SIZE;
                    
                    Entity::maps[entity].src_rect[i][j].w = TILE_SIZE;
                    Entity::maps[entity].src_rect[i][j].h = TILE_SIZE;
                    Entity::maps[entity].dst_rect[i][j].w = TILE_SIZE;
                    Entity::maps[entity].dst_rect[i][j].h = TILE_SIZE;
                    j++;
                } while(delimeter != std::string::npos);
                i++;
            }
        }
    }
    
    void load_map(unsigned int entity, std::string *map_path){
        if((Entity::mask[entity] & RENDER_MASK) == RENDER_MASK){
            std::ifstream tile_map(Game::project_path + *map_path);
            std::string line;
            size_t delimeter;
            int i = 0, j;
            
            while(tile_map >> line){
                j = 0;
                do{
                    delimeter = line.find(',');
                    Entity::maps[entity].t[i][j++] = std::stoi(line.substr(0, delimeter)) + 1;
                    line = line.substr(delimeter + 1);
                } while(delimeter != std::string::npos);
                i++;
            }
        }
    }
    
    void load_texture(std::string *texture_path){
        SDL_Surface *load_file = SDL_LoadBMP(&(Game::project_path + *texture_path)[0]);
        auto texture = SDL_CreateTextureFromSurface(Game::renderer, load_file);
        Entity::textures.emplace_back(texture);
        Entity::dim tx_dim;
        SDL_QueryTexture(texture, NULL, NULL, &tx_dim.w, &tx_dim.h);
        Entity::tx_dimensions.emplace_back(tx_dim);
        SDL_FreeSurface(load_file);
        
    }
    
    void set_texture(unsigned int entity, unsigned int texture_id){
        Entity::texture[entity].texture = Entity::textures[texture_id];
        Entity::texture[entity].texture_id = texture_id;
        if((Entity::mask[entity] & COMPONENT_SIZE) == COMPONENT_SIZE){
             Entity::texture[entity].destignation_rect.w = Entity::size[entity].w;
             Entity::texture[entity].destignation_rect.h = Entity::size[entity].h;
        } else {
            Entity::texture[entity].destignation_rect.w = Entity::tx_dimensions[texture_id].w;
            Entity::texture[entity].destignation_rect.h = Entity::tx_dimensions[texture_id].h;
        }
    }
}


#endif