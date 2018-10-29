#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include "../Game.h"

namespace Entity
{

std::vector<std::string> name(ENTITY_COUNT);
std::vector<int> mask(ENTITY_COUNT);
std::vector<Position> position(ENTITY_COUNT);
std::vector<Displacement> displacement(ENTITY_COUNT);
std::vector<Size> size(ENTITY_COUNT);
std::vector<Texture> texture(ENTITY_COUNT);
std::vector<Collision> collision(ENTITY_COUNT);

int master = -1;

// store textures info
struct dim
{
    int w;
    int h;
};
//    textures db & texture maps
std::vector<SDL_Texture *> textures;
std::vector<dim> tx_dimensions;
std::vector<Map> maps(ENTITY_COUNT);

//	animation textures
std::vector<Animation> animation(ENTITY_COUNT);
std::vector<SDL_Texture *> animations;
std::vector<dim> anim_tx_dim;

//  events animations
std::vector<std::vector<Event>> events(ENTITY_COUNT);

int create_entity()
{

    for (unsigned int entity = 0; entity < ENTITY_COUNT; entity++)
    {
        if (mask[entity] == Component::COMPONENT_NONE)
            return entity;
    }

    return -1;
}

void drop_entity(unsigned int entity)
{
    mask[entity] = Component::COMPONENT_NONE;
}

int search_entity(std::string _name)
{
    for (unsigned int entity = 0; entity < ENTITY_COUNT; entity++)
        if (name[entity] == _name)
            return entity;
    return -1;
}
} // namespace Entity
#endif
