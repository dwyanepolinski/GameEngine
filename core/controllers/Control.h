//
// Created by john on 17.06.18.
//

#ifndef GAMEENGINE_CONTROL_H
#define GAMEENGINE_CONTROL_H


#include "../ECS.h"

class Control : public Component{

public:

    Control();
    char* name = (char *) "control";
    unsigned int speed = 1;

    virtual void keydown(int key_sym);
    virtual void keyup(int key_sym);

};


#endif //GAMEENGINE_CONTROL_H