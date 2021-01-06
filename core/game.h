#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "ecs/systems/render.h"
#include "ecs/systems/control.h"
#include <chrono>


class Game{

    GameContext* ctx;
    unsigned int fps_limit = 0;
    unsigned int fps = 0;
    bool is_running = false;

    void start_systems() {
        new RenderSystem();
        new ControlSystem();
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
        using clock = std::chrono::high_resolution_clock;
        using milliseconds = std::chrono::milliseconds;
        using std::chrono::duration_cast;

        auto start = clock::now(), end = clock::now();

        while(is_running) {
            ctx->set_dt(duration_cast<milliseconds>(end - start).count());
            start = clock::now();

            handle_events();
            update();

            end = clock::now();
            std::cout<<ctx->dt()<<std::endl;
        }
    }

    void load() {
        std::ifstream game_file(ctx->get_wd() + "/demo.def");
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
