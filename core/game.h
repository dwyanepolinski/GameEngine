#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "ecs/systems/render.h"
#include <fstream>


class Game{

    GameContext* ctx;
    unsigned int fps_limit = 0;
    unsigned int fps = 0;
    bool is_running = false;

    void start_systems() {
        new RenderSystem();
    }

    void handle_events() {
        SDL_PollEvent(ctx->sdl_event);

        switch (ctx->sdl_event->type) {
            case SDL_QUIT:
                is_running = false;
                break;
            default:
                SystemManager::handle_events();
        }
    }

    void update() {
        SystemManager::update();
    }

    void loop() {
        while(is_running) {
            handle_events();
            update();
        }
    }

    void load() {
        std::ifstream game_file(ctx->get_wd() + "/demo.def");
        std::string x = ctx->get_wd() + "/demo.def";
        std::string key, value;

        assert(game_file.is_open() && "[CRITICAL] Error reading game file");

        while (game_file >> key >> value) {
            ECSManager::set(std::stoi(key), value);
        }
    }


public:
    Game(std::string wd) {
        ctx = new GameContext(wd);
    }

    ~Game() {
        SDL_DestroyWindow(ctx->window());
        SDL_DestroyRenderer(ctx->renderer());
        SDL_Quit();
        SystemManager::destroy();
        delete ctx;
    }

    void run() {
        ECSManager::init(ctx);
        start_systems();
        ctx->init_sdl();
        load();
        is_running = true; 
        loop(); 
    }
};

#endif
