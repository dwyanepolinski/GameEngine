//
// Created by john on 08.05.18.
//

#ifndef GAMEENGINE_GAME_H
#define GAMEENGINE_GAME_H

#include <SDL2/SDL.h>
#include "Scene.h"


class Game{

public:
    Game(char *path, int x_pos = SDL_WINDOWPOS_CENTERED, int y_pos = SDL_WINDOWPOS_CENTERED, int width = 800, int height = 600, bool fullscreen = false);
    ~Game();

    void main_loop();

    static SDL_Renderer *renderer;
    static Scene *current_scene;
    char* game_data_path;
//    char* window_title = NULL;
//    char* current_scene_name = NULL;
    const int window_width;
    const int window_height;
    std::map<char*, Scene*> scenes;


private:
    bool is_running = false;
    SDL_Window *window;

    void handle_events();
    void update();
    void render();

    void load(char* game_data_path);
    static void definition_file_reader(Game* game, const std::string key, const std::string value);

};


#endif //GAMEENGINE_GAME_H
