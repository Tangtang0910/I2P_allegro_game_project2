#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED

#include "global.h"
#include "window/Window.h"
#include "window/Menu.h"
#include "window/DiningRoom.h"

enum GameState {
    GAME_INIT,
    GAME_EXIT,
    GAME_CONTINUE
};

class GameController {
public:
    GameController();
    ~GameController();
    void window_init();

    GameState game_run();
    GameState process_event();

    void game_establish();
    void game_draw();

private:
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_TIMER *fps = NULL;

    const char *title = "煉朋友術師";
    const float FPS = 60;

    Window *current_window = NULL;
    Window *menu = NULL;
    vector<Window *> windows;
    int window = 0;
    bool draw = false;
};

#endif
