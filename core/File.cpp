//
// Created by john on 09.06.18.
//


#include "File.h"

char* File::BASE_DIR = nullptr;
char* File::GAME_DEF = nullptr;

char *File::build_path(char *file) {
    char *full_path = new char[strlen(File::BASE_DIR) + strlen(file)];
    strcpy(full_path, File::BASE_DIR);
    strcat(full_path, file);
    return full_path;
}

SDL_Texture *File::load_texture(char *file_name) {
    SDL_Surface *load_file = nullptr;
    SDL_Texture *texture = nullptr;
    char* path = build_path(file_name);
    load_file = SDL_LoadBMP(build_path(file_name));

    std::cout << "[*] Loading texture " << file_name << " ...";

    if (load_file) {
        texture = SDL_CreateTextureFromSurface(Game::renderer, load_file);
        SDL_FreeSurface(load_file);
        std::cout << "OK"<< std::endl;
    } else {
        std::cout << std::endl << "[*] SDL load texture error, file name: " << file_name << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return texture;
}

char *File::get_base_dir(char *game_data_path) {
    size_t slash_pos = strlen(game_data_path);
    while(game_data_path[--slash_pos] != '/');
    slash_pos++;
    char* base_dir = new char[slash_pos + 1];
    strncpy(base_dir, game_data_path, slash_pos);
//    shieet, good lesson
    base_dir[slash_pos] = '\0';
    return base_dir;
}

