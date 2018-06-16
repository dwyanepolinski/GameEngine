//
// Created by john on 08.05.18.
//

#include <iostream>
#include "Game.h"
#include "File.h"

SDL_Renderer *Game::renderer = nullptr;
Scene *Game::current_scene = nullptr;

Game::Game(char *path, int x_pos, int y_pos, int width, int height, bool fullscreen) : window_width(width),
                                                                                       window_height(height),
                                                                                       game_data_path(path) {
    std::cout << "[*] Init game object" << std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "[*] SDL Init error" << std::endl;
        std::exit(EXIT_FAILURE);
    }


    window = SDL_CreateWindow("GameEngine", x_pos, y_pos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);

    if (!window) {
        std::cout << "[*] SDL Window error" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cout << "[*] SDL Renderer error" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << "[*] Init SDL2 done" << std::endl;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    load(game_data_path);

    is_running = true;
    std::cout << "[*] Init complete" << std::endl;
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYUP:
            std::cout<<event.key.keysym.sym<<std::endl;
            break;
        default:
            break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    if(current_scene)
        current_scene->render();
    SDL_RenderPresent(renderer);
}

Game::~Game() {
    delete current_scene;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "[*] Game object destroyed";
}

void Game::main_loop() {
    while (is_running) {
        handle_events();
        update();
        render();
    }
}

void Game::update() {

}

void Game::load(char *game_data_path) {
    File::load_defn(game_data_path, this, definition_file_reader, true);
}

void Game::definition_file_reader(Game *game, const std::string key, const std::string value) {
    if (key == "init_scene") {
        char* current_scene_name = (char *) value.c_str();
        game->current_scene = new Scene();
        game->current_scene->load(current_scene_name);
    }
    if(key == "window_title");
        SDL_SetWindowTitle(game->window, value.c_str());
}
