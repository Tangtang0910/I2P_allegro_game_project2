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
    
    bool mouse_click(int startx, int starty, int width, int height, ALLEGRO_EVENT event);

private:
    ALLEGRO_BITMAP *background = NULL;
};

#endif
