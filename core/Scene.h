//
// Created by john on 05.06.18.
//

#ifndef GAMEENGINE_SCENE_H
#define GAMEENGINE_SCENE_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL2/SDL_render.h>
#include "ECS.h"

class Scene : Entity {

public:
    std::vector<Entity*> entities;

    ~Scene();
    void render();
    void load(char *_name);
    static void definition_file_reader(Scene* scene, const std::string key, const std::string value);


private:
    static bool compare_layers(Entity *en_1, Entity *en_2);
};


#endif //GAMEENGINE_SCENE_H
