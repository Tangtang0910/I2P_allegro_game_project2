#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <list>
#include <time.h>
#include "Menu.h"
#include "element.h"


#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

class Alchemy_room
{
public:
    // constructor
    Alchemy_room();

    // each process of scene
    void Alchemy_init();
    void Alchemy_reset();
    void Alchemy_play();
    void Alchemy_begin();

    int Alchemy_run();
    int Alchemy_update();

    void Alchemy_err_msg(int msg);
    void Alchemy_destroy();

    // each drawing scene function
    void draw_Alchemy_running_map();

    // process of updated event
    int process_Alchemy_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    bool isOnPot();
//改成elements
    Element* create_element(int);
    void Alchemy_init();

private:
    ALLEGRO_BITMAP *pot;
    ALLEGRO_BITMAP *element[Num_ElementType];
    ALLEGRO_BITMAP *background = NULL;
//font
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;
//event
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    Menu *menu = NULL;

    std::list<Element*> &ElementSet = DC->get_Element();

    int mouse_x, mouse_y;
    int selectedElement = -1, lastClicked = -1;

    bool redraw = false;
};

#endif // MAINWINDOW_H_INCLUDED