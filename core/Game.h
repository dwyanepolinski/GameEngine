//
// Created by john on 08.05.18.
//

#ifndef GAMEENGINE_GAME_H
#define GAMEENGINE_GAME_H

#include <SDL2/SDL.h>
#include <string>
#include "../math/vect.h"


class Game{

public:
    Game(std::string _def_file_path,
         int x_pos = SDL_WINDOWPOS_CENTERED,
         int y_pos = SDL_WINDOWPOS_CENTERED,
         int width = 800,
         int height = 600,
         bool fullscreen = false);
    
    ~Game();

    void main_loop();

    static SDL_Renderer *renderer;
    static SDL_Event *event;
    
    static std::string def_file_path;
    static std::string project_path;


private:
    bool is_running = false;
    SDL_Window *window;
    unsigned int fps_limit = 0;
    unsigned int fps = 0;


    void handle_events();
    void update();
    void render();

    void load(std::string def_file_path);

};


#endif //GAMEENGINE_GAME_H
