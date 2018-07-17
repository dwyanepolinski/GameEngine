//
// Created by john on 05.06.18.
//

#include "Scene.h"
#include "components/Render.h"
#include "File.h"


void Scene::render() {
    get_component<Render>()->render();

    for (auto const &entity: renderable_entities)
        entity->get_component<Render>()->render();
}

bool Scene::compare_layers(Entity *en_1, Entity *en_2) {
    return en_1->get_component<Render>()->layer < en_2->get_component<Render>()->layer;
}

void Scene::load(char *_name) {
    Entity::load(_name);
    File::load_defn(_name, this, definition_file_reader);
    renderable_entities = ECS::filter_entities<Render>(entities);
    std::sort(renderable_entities.begin(), renderable_entities.end(), compare_layers);
}

void Scene::definition_file_reader(Scene *scene, const std::string key, const std::string value) {
    if(key == "entity"){
        Entity* entity = new Entity();
        scene->entities.push_back(entity);
        entity->load((char *) value.c_str());
    }
    if(key == "cam_size")
        scene->camera_frame = std::stod(value);
}

Scene::~Scene() {
    for (auto const &entity: entities)
        delete entity;
}

void Scene::set_camera(int window_w, int window_h) {
    camera_w = (int) (window_w * camera_frame);
    camera_h = (int) (window_h * camera_frame);
}
