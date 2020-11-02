#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "ecs/systems/render.h"


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
        ctx->init_sdl();
        while(is_running) {
            handle_events();
            update();
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
        is_running = true; 
        loop(); 
    }
};

#endif
