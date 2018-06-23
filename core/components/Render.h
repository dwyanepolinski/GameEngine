//
// Created by john on 06.06.18.
//

#ifndef GAMEENGINE_RENDER_H
#define GAMEENGINE_RENDER_H


#include <SDL2/SDL_system.h>
#include "../ECS.h"

class Render : public Component{

public:
    Render();
    ~Render();
    void load(char* _entity_name);
    static void definition_file_reader(Render* render, const std::string key, const std::string value);

    int layer = 0;
    SDL_Texture* texture = nullptr;
    void render();
    char* name = (char *) "render";
    double scale = 1;

private:
    SDL_Rect* dst_rect;
    int texture_width;
    int texture_height;

};


#endif //GAMEENGINE_RENDER_H
