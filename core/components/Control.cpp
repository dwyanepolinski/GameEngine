//
// Created by john on 17.06.18.
//

#include <cstring>
#include <SDL2/SDL_keycode.h>
#include "Control.h"

Control::Control() {
    char *_name = new char[strlen(name)];
    strcpy(_name, name);
    name = _name;
}

void Control::keydown(int key_sym) {
    switch (key_sym){
        case SDLK_w:
            entity->velocity->y = -1;
            break;
        case SDLK_s:
            entity->velocity->y = 1;
            break;
        case SDLK_a:
            entity->velocity->x = -1;
            break;
        case SDLK_d:
            entity->velocity->x = 1;
            break;
        default:break;
    }
}

void Control::keyup(int key_sym) {
    switch (key_sym){
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
        default:break;
    }
}
