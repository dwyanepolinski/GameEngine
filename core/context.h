#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <string>
#include <assert.h>
#include <math.h>
#include "ilist.h"

class GameContext {

    SDL_Window*   _window;
    SDL_Renderer* _renderer;
    
    std::string working_directory;
    unsigned int window_width, window_height;
    uint64_t dtime;
    bool fullscreen;

    public:

    SDL_Event*    sdl_event;

    GameContext() { 
        assert(0 && "Cant init GameContext, not enough arguments"); 
    }
    GameContext(const std::string wd) {
        working_directory = wd;
        window_width = 800;
        window_height = 600;
    }
    ~GameContext() {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
        SDL_Quit();
    }

    void set_window_params(const unsigned int w, const unsigned int h, const bool f) {
        fullscreen = f;
        if(w >= 800 && h >= 600) {
            window_width = w;
            window_height = h;
        }
    }

    void init_sdl() {
        _window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
        _renderer = SDL_CreateRenderer(_window, -1, 0);
        sdl_event = new SDL_Event;
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    }

    SDL_Renderer* renderer() { return _renderer; } 
    SDL_Window* window() { return _window; }
    const std::string get_wd() { return working_directory; }
    const uint64_t dt() { return dtime; }
    void set_dt(const uint64_t dtime) { this->dtime = dtime; }

};

#endif