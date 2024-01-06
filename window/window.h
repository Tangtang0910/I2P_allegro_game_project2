#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "../global.h"
#include "../utils.h"

class Window {
public:
    Window();
    bool process(ALLEGRO_EVENT event);
    void draw();
    void destroy();

private:
    ALLEGRO_BITMAP *background = NULL;
    Utils *mouse_clicked;
};

#endif // MENU_H_INCLUDED
