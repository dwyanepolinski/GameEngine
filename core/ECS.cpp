//
// Created by john on 14.05.18.
//

#include "ECS.h"
#include "File.h"
#include "controllers/Render.h"
#include <algorithm>

std::vector<Entity *> ECS::entities;

Entity::Entity() {
    ECS::entities.push_back(this);
    std::cout << "[*] Enity created" << std::endl;
}

Entity::~Entity() {
    ECS::entities.erase(std::remove(ECS::entities.begin(), ECS::entities.end(), this), ECS::entities.end());
    for (auto const &component : components)
        delete component.second;
    std::cout << "[*] Enity destroyed " << name << std::endl;
}

void Entity::load(char *_name) {
    File::load_defn(_name, this, definition_file_reader);
    name = new char[strlen(_name)];
    strcpy(name, _name);
    for (auto const &component: components)
        component.second->load(name);
}

void Entity::definition_file_reader(Entity *entity, const std::string key, const std::string value) {
    if(key == "component"){
        if(value == "render")
            entity->add_component<Render>();
    }
}

