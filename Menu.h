#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "global.h"
#include "utils.h"

class Menu
{
public:
    Menu();
    void menu_process(ALLEGRO_EVENT event);
    void menu_draw();
    void menu_destroy();

private:
    Utils *mouse_clicked;
};

#endif // MENU_H_INCLUDED
