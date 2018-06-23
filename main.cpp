#include "core/Game.h"

int main(int argc, char **argv) {
    Game game((char *) "/home/john/ClionProjects/GameEngine/DemoGame/demo.def");
    game.main_loop();

//    Entity e, q;
//
//    e.add_component<Render>();
//    q.add_component<Render>();
//
//    e.get_component<Render>()->layer = 1;
//    q.get_component<Render>()->layer = 0;
//
//    e.id = 0;
//    q.id = 1;
//
//    Scene sc;
//
//    sc.add_entity(&e);
//    sc.add_entity(&q);
//
//    sc.show();

    return 0;
}