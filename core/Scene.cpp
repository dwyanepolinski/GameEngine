//
// Created by john on 05.06.18.
//

#include "Scene.h"
#include "controllers/Render.h"
#include "File.h"


void Scene::render() {
    /* - render map
     * - get all entities from scene with component Render
     * - sort them by Render.layer
     * - render all */

    get_component<Render>()->render();

    auto filtered = ECS::filter_entities<Render>(entities);
    std::sort(filtered.begin(), filtered.end(), compare_layers);

    for (auto const &entity: filtered)
        entity->get_component<Render>()->render();
}

bool Scene::compare_layers(Entity *en_1, Entity *en_2) {
    return en_1->get_component<Render>()->layer < en_2->get_component<Render>()->layer;
}

void Scene::load(char *_name) {
    Entity::load(_name);
    File::load_defn(_name, this, definition_file_reader);
}

void Scene::definition_file_reader(Scene *scene, const std::string key, const std::string value) {
    if(key == "entity"){
        Entity* entity = new Entity();
        scene->entities.push_back(entity);
        entity->load((char *) value.c_str());
    }
}

Scene::~Scene() {
    for (auto const &entity: entities)
        delete entity;
}
