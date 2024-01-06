#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED

#include "global.h"
#include "window/Window.h"
#include "window/Menu.h"

enum GameState {
    GAME_INIT,
    GAME_EXIT,
    GAME_CONTINUE
};

class GameController {
public:
    GameController();

    GameState game_run();
    GameState process_event();

    void game_establish();
    void game_draw();
    void game_destroy();

private:
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_TIMER *fps = NULL;

    const char *title = "煉朋友術師";
    const float FPS = 60;

    Window *menu = NULL;
    int window = 0;
    bool draw = false;
};

#endif
