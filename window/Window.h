#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "../global.h"

class Window {
public:
    Window();
    ~Window();

    virtual bool process(ALLEGRO_EVENT event);
    virtual void draw();

    void set_background(string filename);
    void draw_background();
    void draw_materail();
    bool mouse_click(int startx, int starty, int width, int height, ALLEGRO_EVENT event);

private:
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *pot = NULL;
    ALLEGRO_BITMAP *grass = NULL;
    ALLEGRO_BITMAP *mineral = NULL;
    ALLEGRO_BITMAP *potion = NULL;
};

#endif
