#include "GameWindow.h"

int main(int argc, char *argv[]) {
    GameWindow *game= new GameWindow();
    game->game_establish();
    delete game;
    return 0;
}
