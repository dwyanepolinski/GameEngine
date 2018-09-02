//
// Created by john on 08.05.18.
//

#include <iostream>
#include "Game.h"
#include "File.h"
#include "components/Control.h"

SDL_Renderer *Game::renderer = nullptr;
SDL_Event *Game::event = new SDL_Event;
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

    controllable_entities = ECS::filter_entities<Control>(current_scene->entities);

    is_running = true;
    std::cout << "[*] Init complete" << std::endl;
}

void Game::handle_events() {

    SDL_PollEvent(event);

    switch (event->type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYUP: {
            for (auto const &entity: controllable_entities)
                entity->get_component<Control>()->keyup(event->key.keysym.sym);
        }
            break;
        case SDL_KEYDOWN: {
            for (auto const &entity: controllable_entities)
                entity->get_component<Control>()->keydown(event->key.keysym.sym);
        }
            break;
        default:
            break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    if (current_scene)
        current_scene->render();
    SDL_RenderPresent(renderer);
}

Game::~Game() {
    for (auto const &scene: scenes)
        delete scene.second;
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
    for(auto const& entity: ECS::entities) {
        for(auto const& component: entity->components)
            component.second->update();
    }
}

void Game::load(char *game_data_path) {
    File::load_defn(game_data_path, this, definition_file_reader, true);
    current_scene->set_camera(window_width, window_height);
}

void Game::definition_file_reader(Game *game, const std::string key, const std::string value) {
    if (key == "init_scene") {
        char *current_scene_name = (char *) value.c_str();
        game->current_scene = new Scene();
        game->current_scene->load(current_scene_name);
        game->scenes.insert(std::make_pair(game->current_scene->name, game->current_scene));
    }
    if (key == "window_title");
        SDL_SetWindowTitle(game->window, value.c_str());
    if(key == "fps_limit")
        game->fps_limit = (unsigned int) std::stoi(value);
}
