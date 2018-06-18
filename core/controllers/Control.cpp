//
// Created by john on 17.06.18.
//

#include <cstring>
#include "Control.h"

Control::Control() {
    char *_name = new char[strlen(name)];
    strcpy(_name, name);
    name = _name;
}

void Control::keydown(int key_sym) {
    std::cout << key_sym << std::endl;
}

void Control::keyup(int key_sym) {
    std::cout << key_sym << std::endl;
}
