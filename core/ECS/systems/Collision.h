#ifndef GAMEENGINE_COLLISION_H
#define GAMEENGINE_COLLISION_H

#include "../System.h"
#include "../Entity.h"

namespace CollisionSystem{

#define COLLISION_MASK (COMPONENT_POSITION|COMPONENT_COLLISION)

    void collided(unsigned int first_entity, unsigned int second_entity){
        bool condition1 = Entity::position[first_entity].pos.x < Entity::position[second_entity].pos.x + Entity::collision[second_entity].bbox_w;
        bool condition2 = Entity::position[first_entity].pos.x + Entity::collision[first_entity].bbox_w > Entity::position[second_entity].pos.x;
        bool condition3 = Entity::position[first_entity].pos.y < Entity::position[second_entity].pos.y  + Entity::collision[second_entity].bbox_h;
        bool condition4 = Entity::position[first_entity].pos.y + Entity::collision[first_entity].bbox_h > Entity::position[second_entity].pos.y;

        if(condition1 && condition2 && condition3 && condition4)
            EventSystem::register_event(0, 1, first_entity, second_entity);
            // std::cout<<"COLLISION "<<first_entity<<" "<<second_entity<<std::endl;
    }

    void update(){
        for(unsigned int entity = 0; entity < ENTITY_COUNT; entity++){
            if((Entity::mask[entity] & COLLISION_MASK) == COLLISION_MASK){
                for(unsigned int other_entity = 0; other_entity < ENTITY_COUNT; other_entity++){
                    if((Entity::mask[other_entity] & COLLISION_MASK) == COLLISION_MASK && entity != other_entity && Entity::collision[entity].group != Entity::collision[other_entity].group)
                        collided(entity, other_entity);
                }
            }
        }
    }


}

#endif