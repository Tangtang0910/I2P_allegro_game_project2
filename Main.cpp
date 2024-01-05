#include "GameWindow.h"
int main(int argc, char *argv[])
{

    GameWindow *TowerGame= new GameWindow();

    TowerGame->game_establish();

    delete TowerGame;
    return 0;
}
