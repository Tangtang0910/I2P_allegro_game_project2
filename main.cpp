#include "GameController.h"

int main(int argc, char *argv[]) {
    GameController *controller= new GameController();
    controller->game_establish();
    delete controller;
    return 0;
}

