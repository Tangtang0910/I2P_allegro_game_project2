#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED

#include "global.h"
#include "window/Window.h"
#include "window/Menu.h"
#include "window/DiningRoom.h"
#include "window/Workshop.h"
#include "window/Magic_effect.h"

enum GameState {
    GAME_INIT,
    GAME_EXIT,
    GAME_CONTINUE
};

class GameController {
public:
    GameController();
    ~GameController();

    GameState game_run();
    GameState process_event();

    void game_establish();
    void game_draw();

private:
    ALLEGRO_BITMAP *icon;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_TIMER *fps = NULL;
    ALLEGRO_SAMPLE *song = NULL;

    const char *title = "煉朋友術師";
    const float FPS = 30;

    Window *current_window = NULL;
    Window *menu = NULL;
    Window *dining_room = NULL;
    Window *workshop = NULL;
    Window *magic_effect = NULL;

    bool draw = false;
};

#endif
