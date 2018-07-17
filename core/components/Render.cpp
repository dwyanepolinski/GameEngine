//
// Created by john on 06.06.18.
//

#include "Render.h"
#include "../File.h"

void Render::render() {
    dst_rect->x = (int) entity->position->x;
    dst_rect->y = (int) entity->position->y;
    SDL_RenderCopy(Game::renderer, texture, NULL, dst_rect);
}

Render::Render() {
    char* _name = new char[strlen(name)];
    strcpy(_name, name);
    name = _name;
}

Render::~Render() {
    if(texture)
        SDL_DestroyTexture(texture);
    std::cout << "[*] Component destroyed " << name << std::endl;
}

void Render::load(char* _entity_name) {
    dst_rect = new SDL_Rect;
    char* object_name = new char[strlen(_entity_name) + strlen(name) + 1];
    strcpy(object_name, _entity_name);
    strcat(object_name, "_");
    strcat(object_name, name);
    File::load_defn(object_name, this, definition_file_reader);
}

void Render::definition_file_reader(Render* render, const std::string key, const std::string value) {
    if(key == "texture_path") {
        render->texture = File::load_texture((char *) value.c_str());
        SDL_QueryTexture(render->texture, NULL, NULL, &render->texture_width, &render->texture_height);
        render->dst_rect->w = render->texture_width;
        render->dst_rect->h = render->texture_height;
    }
    if(key == "scale") {
        render->scale = std::stod(value);
        render->dst_rect->w *= render->scale;
        render->dst_rect->h *= render->scale;
    }
}

