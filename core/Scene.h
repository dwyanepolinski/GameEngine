//
// Created by john on 05.06.18.
//

#ifndef GAMEENGINE_SCENE_H
#define GAMEENGINE_SCENE_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL2/SDL_render.h>
// #include "ECS.h"

class Scene{

public:
//     std::vector<Entity*> entities;
//     double camera_frame = 0.8;
// 
    ~Scene();
//     void render();
    void load(char *_name);
    static void definition_file_reader(Scene* scene, const std::string key, const std::string value);

//     Entity *camera = nullptr;
//     void set_camera(int window_w, int window_h);
//    int get_camera_w() { return camera_w; };
//    int get_camera_h() { return camera_h; };


private:
//     static bool compare_layers(Entity *en_1, Entity *en_2);
//     std::vector<Entity *> renderable_entities;
//     int camera_w;
//     int camera_h;
};


#endif //GAMEENGINE_SCENE_H
