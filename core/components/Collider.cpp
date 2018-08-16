//
// Created by john on 25.07.18.
//

#include <cstring>
#include "Collider.h"
#include "Render.h"
#include "../Game.h"

Collider::Collider() {
    _collider = new Vector2D(
            entity->get_component<Render>()->get_texture_w(),
            entity->get_component<Render>()->get_texture_h()
    );
}

void Collider::update() {
//    more colision detection methods soon
    aabb();
}

void Collider::aabb() {
    auto collision_entities = ECS::filter_entities<Collider>(Game::current_scene->entities);
    for (auto const &_entity: ECS::entities) {
        if (_entity->get_component<Collider>()->layer == layer) {
            if (entity->position->x + entity->width >= _entity->position->x &&
                _entity->position->x + _entity->width >= entity->position->x &&
                entity->position->y + entity->height >= _entity->position->y &&
                _entity->position->y + _entity->height >= entity->position->y) {
                colision(_entity);
                _entity->get_component<Collider>()->colision(entity);
            }
        }
    }
}

void Collider::colision(const Entity* _entity) {
    std::cout << "Collision with " << _entity << std::endl;
}
