#include <iostream>
#include "Entity.h"
#include "Player.h"

void Hello(Entity* e) {
    e->SayHello();
}

int main(int argc, char * argv[]) {
    Entity* p = new Entity();
    Player* e = new Player();

    Hello(p);
    Hello(e);
    
    return 0;
}