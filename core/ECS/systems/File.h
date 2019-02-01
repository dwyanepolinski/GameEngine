#pragma once
#include "Texture.h"
#include "../Entity.h"
#include "Animation.h"
#include "../System.h"
#include <fstream>
#include<assert.h>

namespace FileSystem
{

void init_components(unsigned int entity, const std::string &key, const std::string &value)
{
    if (key == "position_x")
    {
        Entity::position[entity].pos.x = std::stoi(value);
        Entity::mask[entity] |= Component::COMPONENT_POSITION;
    }
    else if (key == "position_y")
        Entity::position[entity].pos.y = std::stoi(value);
    else if (key == "texture")
    {
        TextureSystem::set_texture(entity, std::stoi(value));
        Entity::mask[entity] |= Component::COMPONENT_TEXTURE;
    }
    else if (key == "width")
    {
        Entity::size[entity].w = Entity::texture[entity].destignation_rect.w = std::stoi(value);
        Entity::mask[entity] |= Component::COMPONENT_SIZE;
    }
    else if (key == "height")
        Entity::size[entity].h = Entity::texture[entity].destignation_rect.h = std::stoi(value);
    else if (key == "speed")
    {
        Entity::displacement[entity].v = std::stof(value);
        Entity::mask[entity] |= Component::COMPONENT_DISPLACEMENT;
    }
    else if (key == "master")
        Entity::master = entity;
    else if (key == "txmap")
    {
        TextureSystem::load_map(entity, value);
        Entity::mask[entity] |= Component::COMPONENT_TXMAP;
    }
    else if (key == "anim")
    {
        TextureSystem::set_anim_texture(entity, std::stoi(value));
        Entity::mask[entity] |= COMPONENT_ANIMATION;
    }
    else if (key == "anim_params"){
        //Entity::animation_params[entity][Entity::events[entity].size()-1]
    }
}

void init(const std::string &def_file_path)
{
    std::ifstream def_file(def_file_path);
    std::string key, value;
    int entity;

    assert(def_file.is_open() && "[CRITICAL] Error reading definition file");
    def_file.is_open();
    while (def_file >> key >> value)
    {
        if (key == NEW_ENTITY)
        {
            entity = Entity::create_entity();
            assert((entity != -1) && "[CRITICAL] Out of Entities");
            Entity::mask[entity] = Component::COMPONENT_NONE;
        }
        else if (key == LOAD_TEXTURE)
            TextureSystem::load_texture(value);
        else if (key == LOAD_ANIMATION_TX)
            TextureSystem::load_animation_texture(value);
        else if (key == LOAD_EVENT)
            AnimationSystem::addEventAnimation(entity, static_cast<Event>(std::stoi(value)));
        else
            init_components(entity, key, value);
    }
}
} // namespace FileSystem
