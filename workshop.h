#ifndef WORKSHOP_H_INCLUDED
#define WORKSHOP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "global.h"
#include "utils.h"

class Alchemy_room
{
public:
    Alchemy_room();
    bool alchemy_room_process(ALLEGRO_EVENT event);
    void alchemy_room_draw();
    void alchemy_room_destroy();

private:
    Utils *mouse_clicked;

    ALLEGRO_BITMAP *alchemy_room_background = NULL;
};

#endif
