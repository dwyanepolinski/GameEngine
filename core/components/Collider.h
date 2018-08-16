//
// Created by john on 25.07.18.
//

#ifndef GAMEENGINE_COLLIDER_H
#define GAMEENGINE_COLLIDER_H


#include "../ECS.h"

class Collider : public Component{

public:

    Vector2D* _collider;
    double scale = 1;
    int layer = 0;

    char* name = (char *) "collider";

    Collider();

    void update();
    void colision(const Entity* _entity);
    void aabb();

};


#endif //GAMEENGINE_COLLIDER_H
