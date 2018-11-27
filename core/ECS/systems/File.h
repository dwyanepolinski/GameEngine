

#ifndef GAMEENGINE_FILE_H
#define GAMEENGINE_FILE_H

#pragma once
#include "Texture.h"
#include "../Entity.h"
#include "../System.h"
#include "Collision.h"
#include <fstream>
#include <assert.h>

namespace FileSystem{
    
    inline void init_components(unsigned int entity, std::string *key, std::string *value){
        if(*key == "position_x"){
            Entity::position[entity].pos.x = std::stoi(*value);
            Entity::mask[entity] |= Component::COMPONENT_POSITION;
        }
        else if(*key == "position_y")
            Entity::position[entity].pos.y = std::stoi(*value);
        else if(*key == "texture"){
            TextureSystem::set_texture(entity, std::stoi(*value));
            RenderSystem::add_entity(entity);
        }
        else if(*key == "width"){
            Entity::size[entity].w = Entity::texture[entity].destignation_rect.w = std::stoi(*value);
            Entity::mask[entity] |= Component::COMPONENT_SIZE;
        }
        else if(*key == "height")
            Entity::size[entity].h = Entity::texture[entity].destignation_rect.h = std::stoi(*value);
        else if(*key == "speed"){
            Entity::displacement[entity].v = std::stof(*value);
            Entity::mask[entity] |= Component::COMPONENT_DISPLACEMENT;
        }
        else if(*key == "master")
            Entity::master = entity;
        else if(*key == "bbox_w"){
            Entity::collision[entity].bbox_w = std::stoi(*value);
            CollisionSystem::add_entity(entity);
        }
        else if(*key == "bbox_h")
            Entity::collision[entity].bbox_h = std::stoi(*value);
        else if(*key == "group")
            Entity::collision[entity].group = std::stoi(*value);
        else if(*key == "cbbt")
            CollisionSystem::_private::cam_bbox_top = entity;
        else if(*key == "cbbb")
            CollisionSystem::_private::cam_bbox_bottom = entity;
        else if(*key == "cbbl")
            CollisionSystem::_private::cam_bbox_left = entity;
        else if(*key == "cbbr")
            CollisionSystem::_private::cam_bbox_right = entity;
    }
    
    void init(std::string def_file_path){
        std::ifstream def_file(def_file_path);
        std::string key, value;
        int entity;
        
        assert(def_file.is_open() && "[CRITICAL] Error reading definition file");
        
        while (def_file >> key >> value) {
            if(key == NEW_ENTITY){
                entity = Entity::create_entity();
                assert((entity != -1) && "[CRITICAL] Out of Entities");
                Entity::mask[entity] = Component::COMPONENT_NONE;
            }
            else if (key == LOAD_TEXTURE)
                TextureSystem::load_texture(&value);
            else if (key == WINDOW_WIDTH)
                Game::window_width = std::stoi(value);
            else if (key == WINDOW_HEIGHT)
                Game::window_heigth = std::stoi(value);
            else if (key == CAMERA_ENABLED)
                Game::camera = (bool) std::stoi(value);
            else
                init_components(entity, &key, &value);
        }
    }
};


#endif

