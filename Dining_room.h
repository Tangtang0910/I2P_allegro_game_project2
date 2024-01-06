#ifndef DININGROOM_H_INCLUDED
#define DININGROOM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "global.h"
#include "utils.h"

class Dining_room
{
public:
    Dining_room();
    bool dining_room_process(ALLEGRO_EVENT event);
    void dining_room_draw();
    void dining_room_destroy();

private:
    Utils *mouse_clicked;

    ALLEGRO_BITMAP *dining_room_background = NULL;
};

#endif // MENU_H_INCLUDED
