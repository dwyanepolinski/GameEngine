#ifndef GAMEENGINE_COLLISION_H
#define GAMEENGINE_COLLISION_H

#include "../System.h"
#include "../Entity.h"

namespace CollisionSystem{

#define COLLISION_MASK (COMPONENT_POSITION|COMPONENT_COLLISION)

    namespace _private{
        std::list<unsigned int> collidables;
        int cam_bbox_top = -1;
        int cam_bbox_bottom = -1;
        int cam_bbox_left = -1; 
        int cam_bbox_right = -1;
    }

    unsigned int COLLISION_EVENT = 0;

    void add_entity(unsigned int entity){
        if((Entity::mask[entity] & COMPONENT_POSITION) != COMPONENT_POSITION)
            return;
        if((Entity::mask[entity] & COLLISION_MASK) != COLLISION_MASK)
            Entity::mask[entity] |= Component::COMPONENT_COLLISION;
        _private::collidables.emplace_back(entity);
    }

    void check_collision(unsigned int first_entity, unsigned int second_entity){
        bool condition1 = Entity::position[first_entity].pos.x < Entity::position[second_entity].pos.x + Entity::collision[second_entity].bbox_w;
        bool condition2 = Entity::position[first_entity].pos.x + Entity::collision[first_entity].bbox_w > Entity::position[second_entity].pos.x;
        bool condition3 = Entity::position[first_entity].pos.y < Entity::position[second_entity].pos.y  + Entity::collision[second_entity].bbox_h;
        bool condition4 = Entity::position[first_entity].pos.y + Entity::collision[first_entity].bbox_h > Entity::position[second_entity].pos.y;

        if(condition1 && condition2 && condition3 && condition4)
            EventSystem::register_event(COLLISION_EVENT, first_entity, second_entity);
    }

    void update(){
        for(auto const& col_1 : _private::collidables){
            for(auto const& col_2 : _private::collidables){
                if(col_1 != col_2 && Entity::collision[col_1].group != Entity::collision[col_2].group)
                    check_collision(col_1, col_2);
            }
        }
    }


}

#endif