//
// Created by john on 17.06.18.
//

#include <cstring>
#include <SDL2/SDL_keycode.h>
#include "Control.h"
#include "../Game.h"
#include "Render.h"

Control::Control() {
    char *_name = new char[strlen(name)];
    strcpy(_name, name);
    name = _name;
}

void Control::keydown(int key_sym) {
//    std::cout<<std::endl<<*entity->velocity<<std::endl;
    switch (key_sym) {
        case SDLK_w:
//        std::cout<<"w"<<std::endl;
            entity->velocity->y = -1;
            break;
        case SDLK_s:
//            std::cout<<"s"<<std::endl;
            entity->velocity->y = 1;
            break;
        case SDLK_a:
//            std::cout<<"a"<<std::endl;
            entity->velocity->x = -1;
            break;
        case SDLK_d:
//            std::cout<<"d"<<std::endl;
            entity->velocity->x = 1;
            break;
        default:
            break;
    }
//    std::cout<<*entity->velocity<<std::endl;
//    camera();
//    std::cout << (int) Game::current_scene->get_camera_w() << std::endl;
//    std::cout << (int) Game::current_scene->get_camera_h() << std::endl;
}

void Control::keyup(int key_sym) {
    switch (key_sym) {
        case SDLK_w:
            entity->velocity->y = 0;
            break;
        case SDLK_s:
            entity->velocity->y = 0;
            break;
        case SDLK_a:
            entity->velocity->x = 0;
            break;
        case SDLK_d:
            entity->velocity->x = 0;
            break;
        default:
            break;
    }
}

void Control::camera() {
    int camera_width = Game::current_scene->get_camera_w();
    int camera_height = Game::current_scene->get_camera_h();
    int window_width = Game::current_scene->get_component<Render>()->get_texture_w();
    int window_height = Game::current_scene->get_component<Render>()->get_texture_h();

    int camera_x_border = (window_width - camera_width) / 2;
    int camera_y_border = (window_height - camera_height) / 2;

    int entity_width = entity->get_component<Render>()->get_texture_w();
    int entity_height = entity->get_component<Render>()->get_texture_h();

//    TODO: set w and h for entities
    Vector2D *entity_velocity_copy = new Vector2D(*entity->velocity);

    Game::current_scene->speed = entity->speed;

    if(entity->position->x <= camera_x_border){
        if(Game::current_scene->position->x < 0){
            Game::current_scene->velocity->x = 1;
            entity->velocity->x = 0;
        }

//        entity->velocity->x = 0;
//        Game::current_scene->velocity->x = -1;

    }
    std::cout<<*entity->position<<std::endl;
    std::cout<<*entity->position<<std::endl;

    if(entity->position->x + entity_width >= camera_x_border + camera_width){
        if(Game::current_scene->position->x + window_width > 800){
            Game::current_scene->velocity->x = -1;
            entity->velocity->x = 0;
        }
    }

}
