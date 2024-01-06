#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include <list>
#include <time.h>
#include "Menu.h"
#include "Dining_room.h"
#include "workshop.h"

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

    Menu *menu = NULL;
    Dining_room *dining_room = NULL;
    Alchemy_room *alchemy_room = NULL;
    int window = 0;
    bool draw = false;
    const char *title = "煉朋友術師";

    // clock rate
    const float FPS = 60;
};

#endif // MAINWINDOW_H_INCLUDED
