#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include <list>
#include <time.h>
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

    Menu *menu = NULL;
    int window = 0;
    bool draw = false;
};

#endif // MAINWINDOW_H_INCLUDED
