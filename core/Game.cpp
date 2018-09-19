//
// Created by john on 08.05.18.
//

#include <iostream>
#include "Game.h"
#include "ECS/Entity.h"
#include "ECS/systems/Render.h"
#include "ECS/systems/File.h"
#include "ECS/systems/Control.h"

SDL_Renderer *Game::renderer = nullptr;
SDL_Event *Game::event = new SDL_Event;
std::string Game::def_file_path = "";
std::string Game::project_path = "";

Game::Game(
    std::string _def_file_path,
    int x_pos,
    int y_pos,
    int width,
    int height,
    bool fullscreen) {
    
    Game::def_file_path = _def_file_path;
    Game::project_path = _def_file_path.substr(0, _def_file_path.rfind("/"));
              
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
    load(def_file_path);


    is_running = true;
    std::cout << "[*] Init complete" << std::endl;
}

void Game::handle_events() {

    SDL_PollEvent(event);

    switch (event->type) {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            ControlSystem::event_handler(event);
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    RenderSystem::render();
    SDL_RenderPresent(renderer);
}

Game::~Game() {
//     deallocate all 
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "[*] Game object destroyed";
}

void Game::main_loop() {
    unsigned int frame_ticks_start, frame_ticks_stop, ticks_now, frames = 0;
    unsigned int prev_ticks = SDL_GetTicks();
    const int delay = fps_limit ? 1000 / fps_limit : 0;

    while (is_running) {
        frame_ticks_start = SDL_GetTicks();

        handle_events();
        update();
        render();

        frames++;

        if (fps_limit) {
            frame_ticks_stop = SDL_GetTicks() - frame_ticks_start;
            if (delay > frame_ticks_stop)
                SDL_Delay(delay - frame_ticks_stop);
        }

        ticks_now = SDL_GetTicks();
        if (ticks_now > prev_ticks + 1000) {
            prev_ticks = ticks_now;
            fps = frames;
            std::cout << "FPS: " << fps << std::endl;
            frames = 0;
        }
    }
}

void Game::update() {
    ControlSystem::update();
}

void Game::load(std::string def_file_path) {
    FileSystem::init(def_file_path); 
}
