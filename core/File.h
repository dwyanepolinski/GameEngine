//
// Created by john on 09.06.18.
//

#ifndef GAMEENGINE_FILE_H
#define GAMEENGINE_FILE_H


#include "Scene.h"
#include "Game.h"
#include <fstream>

class File {

public:

    static char* BASE_DIR;
    static char* GAME_DEF;

    template<typename T> static void load_defn(char* name, T* _object, void (*def_reader)(T* object, const std::string key, const std::string value), bool init_read = false) {
        if(init_read) {
            File::BASE_DIR = get_base_dir(name);
            File::GAME_DEF = name;
            std::cout << "[*] GAME_DEF " << File::GAME_DEF<<std::endl;
            std::cout << "[*] BASE_DIR " << File::BASE_DIR <<std::endl;
        }

        std::ifstream defn_file(File::GAME_DEF);
        std::string key, value;
        bool read = false;
        char* object_name = (char *) (init_read ? "__GAME__" : name);

        assert(defn_file.is_open() && "[CRITICAL] Error reading definition file");

        while (defn_file >> key >> value) {
            if (key == "BEGIN" && value == object_name) {
                std::cout<<"[*] File reader start : ObjectType<" << typeid(_object).name() << ">, name: " << object_name << std::endl;
                read = true;
            }
            else if (key == "END" && value == object_name) {
                std::cout<<"[*] File reader stop : ObjectType<" << typeid(_object).name() << ">, name: " << object_name << std::endl;
                break;
            }
            else if (read)
                (*def_reader)(_object, key, value);
        }
    }

    static SDL_Texture* load_texture(char* file_name);
    static char* build_path(char *file);
    static char* get_base_dir(char* game_data_path);
};


#endif //GAMEENGINE_FILE_H
