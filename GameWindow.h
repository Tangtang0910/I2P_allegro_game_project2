#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include <list>
#include <time.h>
#include "Menu.h"


#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;
const int Coin_Time_Gain = 1;

class GameWindow
{
public:
    // constructor
    GameWindow();

    // each process of scene
    int game_establish();

    int game_run();
    void game_update();

    // each drawing scene function
    void game_draw();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    //bool mouse_hover(int, int, int, int);
    void game_destroy();

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_TIMER *fps = NULL;

    Menu *menu = NULL;

    int window = 0;
    bool draw = false;
    const char *title = "煉朋友術師";
};


#endif // MAINWINDOW_H_INCLUDED

